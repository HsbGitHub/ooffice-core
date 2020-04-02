﻿/*
 * (c) Copyright Ascensio System SIA 2010-2017
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */


#include "Shape.h"
#include "../SlideLayout.h"
#include "../SlideMaster.h"
#include "../Slide.h"
#include "SpTree.h"

namespace PPTX
{
	namespace Logic
	{
		Shape::Shape(std::wstring name_)
		{
			m_name = name_;
		}

		Shape::~Shape()
		{
		}

		Shape::Shape(XmlUtils::CXmlNode& node)
		{
			fromXML(node);
		}
		const Shape& Shape::operator =(XmlUtils::CXmlNode& node)
		{
			fromXML(node);
			return *this;
		}
		Shape::Shape(XmlUtils::CXmlLiteReader& oReader)
		{
			fromXML(oReader);
		}
		const Shape& Shape::operator =(XmlUtils::CXmlLiteReader& oReader)
		{
			fromXML(oReader);
			return *this;
		}
		void Shape::fromXML(XmlUtils::CXmlLiteReader& oReader)
		{
			m_name = oReader.GetName();

			ReadAttributes( oReader );
			
			if ( oReader.IsEmptyNode() )
				return;
					
			int nParentDepth = oReader.GetDepth();
			while( oReader.ReadNextSiblingNode( nParentDepth ) )
			{
				std::wstring strName = XmlUtils::GetNameNoNS(oReader.GetName());

				if (_T("nvSpPr") == strName)
					nvSpPr = oReader;
				else if (_T("spPr") == strName)
					spPr = oReader;
				else if (_T("style") == strName)
					style = oReader;
				else if (_T("txBody") == strName)
					txBody = oReader;
				else if (_T("txXfrm")  == strName)
					txXfrm = oReader;
				else if (_T("txbx") == strName || _T("textbox") == strName)
					txBody = oReader;
				else if (_T("cNvPr") == strName)
					nvSpPr.cNvPr = oReader;
				else if (_T("cNvSpPr") == strName)
					nvSpPr.cNvSpPr = oReader;
				else if (_T("txSp") == strName)
					txBody = oReader;
				else if (_T("bodyPr") == strName)
					TextBoxBodyPr = oReader;
			}
			FillParentPointersForChilds();
		}
		void Shape::fromXML(XmlUtils::CXmlNode& node)
		{
			m_name = node.GetName();

			node.ReadAttributeBase(L"useBgFill", attrUseBgFill);

			XmlUtils::CXmlNodes oNodes;
			if (node.GetNodes(_T("*"), oNodes))
			{
				int nCount = oNodes.GetCount();
				for (int i = 0; i < nCount; ++i)
				{
					XmlUtils::CXmlNode oNode;
					oNodes.GetAt(i, oNode);

					std::wstring strName = XmlUtils::GetNameNoNS(oNode.GetName());

					if (_T("nvSpPr") == strName)
						nvSpPr = oNode;
					else if (_T("spPr") == strName)
						spPr = oNode;
					else if (_T("style") == strName)
						style = oNode;
					else if (_T("txBody") == strName)
						txBody = oNode;
					else if (_T("txXfrm")  == strName)
						txXfrm = oNode;
					else if (_T("txbx") == strName || _T("textbox") == strName)
					{
						XmlUtils::CXmlNode _node = oNode.ReadNode(_T("w:txbxContent"));
						if (_node.IsValid())
							TextBoxShape = _node.GetXml();
					}
					else if (_T("cNvPr") == strName)
					{
						nvSpPr.cNvPr = oNode;
					}
					else if (_T("cNvSpPr") == strName)
					{
						nvSpPr.cNvSpPr = oNode;
					}
					else if (_T("txSp") == strName)
					{
						txBody = oNode.ReadNodeNoNS(_T("txBody"));
					}
					else if (_T("bodyPr") == strName)
					{
						TextBoxBodyPr = oNode;
					}
				}
			}

			FillParentPointersForChilds();
		}
		std::wstring Shape::toXML() const
		{
			XmlUtils::CAttribute oAttr;
			oAttr.Write(_T("useBgFill"), attrUseBgFill);

			XmlUtils::CNodeValue oValue;
			oValue.Write(nvSpPr);
			oValue.Write(spPr);
			oValue.WriteNullable(style);
			oValue.WriteNullable(txBody);

			return XmlUtils::CreateNode(m_name, oAttr, oValue);
		}		

		void Shape::toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
		{
			std::wstring name_ = m_name;

			if		(pWriter->m_lDocType == XMLWRITER_DOC_TYPE_DOCX)	name_ = L"wps:wsp";
			else if (pWriter->m_lDocType == XMLWRITER_DOC_TYPE_XLSX)	name_ = L"xdr:sp";
				
			pWriter->StartNode(name_);

			pWriter->StartAttributes();
			pWriter->WriteAttribute(_T("useBgFill"), attrUseBgFill);
			pWriter->EndAttributes();

			if (pWriter->m_lDocType == XMLWRITER_DOC_TYPE_DOCX)
			{
				nvSpPr.cNvSpPr.toXmlWriter2(_T("wps"), pWriter);
			}
			else
				nvSpPr.toXmlWriter(pWriter);
			
			bool bIsPresentStyle = false;
			if (style.is_init() && (style->fillRef.idx.is_init() || style->fillRef.Color.Color.is_init()))
			{
				bIsPresentStyle = true;
			}
			if (pWriter->m_lGroupIndex > 1 && !bIsPresentStyle)
			{
				pWriter->m_lFlag += 0x02;
			}
			spPr.toXmlWriter(pWriter);
			if (pWriter->m_lGroupIndex > 1 && !bIsPresentStyle)
			{
				pWriter->m_lFlag -= 0x02;
			}

			if (style.is_init())
			{
				if		(pWriter->m_lDocType == XMLWRITER_DOC_TYPE_DOCX)	style->m_namespace = _T("wps");
				else if (pWriter->m_lDocType == XMLWRITER_DOC_TYPE_XLSX)	style->m_namespace = _T("xdr");

                pWriter->Write(style);
            }

			if (pWriter->m_lDocType != XMLWRITER_DOC_TYPE_DOCX)
			{
				if (pWriter->m_lDocType == XMLWRITER_DOC_TYPE_XLSX && txBody.is_init())
					txBody->m_name = _T("xdr:txBody");
				pWriter->Write(txBody);
			}

			if (pWriter->m_lDocType == XMLWRITER_DOC_TYPE_DOCX)
			{	
				bool bIsWritedBodyPr = false;
				if (TextBoxShape.is_init())
				{
					pWriter->WriteString(_T("<wps:txbx>"));
					pWriter->WriteString(*TextBoxShape);
					pWriter->WriteString(_T("</wps:txbx>"));

					if (TextBoxBodyPr.is_init())
					{
						TextBoxBodyPr->m_namespace = _T("wps");
						TextBoxBodyPr->toXmlWriter(pWriter);
						bIsWritedBodyPr = true;
					}
				}
				else if (txBody.is_init())
				{
					txBody->m_name = _T("wps:txBody");
					pWriter->Write(txBody);
				}

                if (!bIsWritedBodyPr)
				{
					pWriter->WriteString(_T("<wps:bodyPr rot=\"0\"><a:prstTxWarp prst=\"textNoShape\"><a:avLst/></a:prstTxWarp><a:noAutofit/></wps:bodyPr>"));
				}
			}

			pWriter->EndNode(name_);
		}
		
		void Shape::fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
        {
            LONG _end_rec = pReader->GetPos() + pReader->GetLong() + 4;

			pReader->Skip(1); // start attributes

			while (true)
			{
				BYTE _at = pReader->GetUChar_TypeNode();
				if (_at == NSBinPptxRW::g_nodeAttributeEnd)
					break;

				switch (_at)
				{
					case 0:
					{
						attrUseBgFill = pReader->GetBool();
						break;
					}
					default:
						break;
				}
			}

			while (pReader->GetPos() < _end_rec)
			{
				BYTE _at = pReader->GetUChar();
				switch (_at)
				{
					case 0:
					{
						nvSpPr.fromPPTY(pReader);
						break;
					}
					case 1:
					{
						spPr.fromPPTY(pReader);
						break;
					}
					case 2:
					{
						style = new ShapeStyle(L"p");
						style->fromPPTY(pReader);
						break;
					}
					case 3:
					{
						txBody = new TxBody();
						txBody->fromPPTY(pReader);
						break;
					}
					case 4:
					{
						if (NULL != pReader->m_pMainDocument)
						{
                            LONG lLenRec = pReader->GetLong();

                            LONG lPosition = pReader->GetPos();
                            LONG lSize_Reader = pReader->GetSize();
							BYTE* pData_Reader = pReader->GetData();
			
							std::wstring sXmlContent;
							pReader->m_pMainDocument->getXmlContent(*pReader, lLenRec, sXmlContent);

							std::wstring strC = _T("<w:txbxContent>");
							strC += sXmlContent;
							strC += _T("</w:txbxContent>");
							TextBoxShape = strC;

							//pReader->Seek(lPosition + lLenRec);
							pReader->Init(pData_Reader, lPosition + lLenRec, lSize_Reader - (lPosition + lLenRec));
						}
						else
						{
							pReader->SkipRecord();
						}
						break;
					}
					case 5:
					{
						TextBoxBodyPr = new PPTX::Logic::BodyPr();
						TextBoxBodyPr->fromPPTY(pReader);
						break;
					}
					case 6:
					{
						txXfrm = new PPTX::Logic::Xfrm();
						txXfrm->fromPPTY(pReader);
						break;
					}
					default:
					{
						break;
					}
				}
			}

			pReader->Seek(_end_rec);
		}



		void Shape::FillParentPointersForChilds()
		{
			nvSpPr.SetParentPointer(this);
			spPr.SetParentPointer(this);
			if(style.IsInit())
				style->SetParentPointer(this);
			if(txBody.IsInit())
				txBody->SetParentPointer(this);
			levelUp = NULL;
		}
		
		void Shape::toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter)const
		{
			pWriter->StartRecord(SPTREE_TYPE_SHAPE);

			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeStart);
			pWriter->WriteBool2(0, attrUseBgFill);
			pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeEnd);

			pWriter->WriteRecord1(0, nvSpPr);
			pWriter->WriteRecord1(1, spPr);
			pWriter->WriteRecord2(2, style);

			if (pWriter->m_pMainDocument != NULL)
			{
				if (TextBoxShape.is_init())
				{					
                    long lDataSize = 0;
                    ULONG lPos = pWriter->GetPosition();
					pWriter->SetPosition(lPos);
					pWriter->StartRecord(4);
					pWriter->m_pMainDocument->getBinaryContent(TextBoxShape.get(), *pWriter, lDataSize);
					pWriter->EndRecord();
					
					if (TextBoxBodyPr.is_init())
					{
						pWriter->StartRecord(5);
						TextBoxBodyPr->toPPTY(pWriter);
						pWriter->EndRecord();
					}
				}
				else if (txBody.is_init())
				{
					std::wstring strContent = txBody->GetDocxTxBoxContent(pWriter, style);

                    long lDataSize = 0;
                    ULONG lPos = pWriter->GetPosition();
					pWriter->SetPosition(lPos);
					pWriter->StartRecord(4);
					pWriter->m_pMainDocument->getBinaryContent(strContent, *pWriter, lDataSize);
					pWriter->EndRecord();

					pWriter->WriteRecord2(5, txBody->bodyPr);
				}
			}
			else
			{
				pWriter->WriteRecord2(3, txBody);
			}

			pWriter->WriteRecord2(6, txXfrm);
			
			pWriter->EndRecord();
		}


		void Shape::GetRect(Aggplus::RECT& pRect)const
		{
			pRect.bottom = 0;
			pRect.left = 0;
			pRect.right = 0;
			pRect.top = 0;

			if(spPr.xfrm.is_init())
			{
				pRect.left		= spPr.xfrm->offX.get_value_or(0);
				pRect.top		= spPr.xfrm->offY.get_value_or(0);
				pRect.right		= pRect.left + spPr.xfrm->extX.get_value_or(0);
				pRect.bottom	= pRect.top + spPr.xfrm->extY.get_value_or(0);
			}
			//else
			//{
			//	if(bMergeWithLevelUp)
			//	{
			//		FillLevelUp();
			//		if(levelUp != NULL)
			//			levelUp->GetRect(pRect);
			//	}
			//}
			if(parentIs<Logic::SpTree>())
				parentAs<Logic::SpTree>().NormalizeRect(pRect);
		}

		void Shape::FillLevelUp()const
		{
			if((levelUp == NULL) && (nvSpPr.nvPr.ph.IsInit()))
			{
				if((nvSpPr.nvPr.ph->type.IsInit()) || (nvSpPr.nvPr.ph->idx.IsInit()))
				{
					if(parentFileIs<Slide>())
						parentFileAs<Slide>().Layout->GetLevelUp(*this);
					else if(parentFileIs<SlideLayout>())
						parentFileAs<SlideLayout>().Master->GetLevelUp(*this);
				}
			}
		}

		void Shape::FillShapeProperties(ShapeProperties& props)
		{
			//props.SetParentFilePointer(*parentFile);
			if(parentFileIs<SlideMaster>())
			{
				std::wstring type = nvSpPr.nvPr.ph.IsInit()?nvSpPr.nvPr.ph->type.get_value_or(_T("body")):_T("");
				//if( (nvSpPr->cNvSpPr->txBox.get_value_or(false)) && (type == "") )
				//	type = "text-box";
				parentFileAs<SlideMaster>().FillShapeProperties(props, type);
				props.FillFromTextBody(txBody);
				if(style.IsInit())
					props.FillFontRef(style->fontRef);

				//props.SetParentFilePointer(parentFile);
			}
			else if(parentFileIs<SlideLayout>())
			{
				//FillLevelUp();
				//if(levelUp != NULL)
				//	levelUp->GetShapeProperties(props);
				//else
				//{
					std::wstring type = nvSpPr.nvPr.ph.IsInit()?nvSpPr.nvPr.ph->type.get_value_or(_T("body")):_T("");
					//if( (nvSpPr->cNvSpPr->txBox.get_value_or(false)) && (type == "") )
					//	type = "text-box";
					parentFileAs<SlideLayout>().FillShapeProperties(props, type);
				//}

				props.FillFromTextBody(txBody);
				if(style.IsInit())
					props.FillFontRef(style->fontRef);

				//props.SetParentFilePointer(parentFile);
			}
			else if(parentFileIs<Slide>())
			{
				//FillLevelUp();
				//if(levelUp != NULL)
				//	levelUp->GetShapeProperties(props);
				//else
				//{
					std::wstring type = nvSpPr.nvPr.ph.is_init()?nvSpPr.nvPr.ph->type.get_value_or(_T("body")):_T("");
					//if( (nvSpPr->cNvSpPr->txBox.get_value_or(false)) && (type == "") )
					//	type = "text-box";
					parentFileAs<Slide>().FillShapeProperties(props, type);
				//}

				props.FillFromTextBody(txBody);
				if(style.IsInit())
					props.FillFontRef(style->fontRef);

				//props.SetParentFilePointer(parentFile);
			}
			props.SetParentFilePointer(parentFile);
		}

		void Shape::FillShapeTextProperties(CShapeTextProperties& props)
		{
			std::wstring type = nvSpPr.nvPr.ph.IsInit()?nvSpPr.nvPr.ph->type.get_value_or(_T("body")):_T("");
			if (parentFileIs<SlideMaster>())
			{
				parentFileAs<SlideMaster>().FillShapeTextProperties(props, type);
				props.FillFromTextBody(txBody, NULL);
				if (style.IsInit())
					props.FillFontRef(style->fontRef, isFontRefInSlide);
			}
			else if (parentFileIs<SlideLayout>())
			{
				parentFileAs<SlideLayout>().FillShapeTextProperties(props, type);
				props.FillFromTextBody(txBody, NULL);
				if(style.IsInit())
					props.FillFontRef(style->fontRef, isFontRefInSlide);
			}
			else if (parentFileIs<Slide>())
			{
				parentFileAs<Slide>().FillShapeTextProperties(props, type);
				props.FillFromTextBody(txBody, body);
				if(style.IsInit())
					props.FillFontRef(style->fontRef, isFontRefInSlide);
			}

			props.SetParentFilePointer(parentFile);
		}

		DWORD Shape::GetFill(UniFill& fill)const
		{
			DWORD BGRA = 0;
			//fill.SetParentFilePointer(*parentFile);

			if(style.IsInit())
			{
				if(parentFileIs<PPTX::Slide>())
					parentFileAs<PPTX::Slide>().theme->GetFillStyle(style->fillRef.idx.get_value_or(0), fill);
				else if(parentFileIs<PPTX::SlideLayout>())
					parentFileAs<PPTX::SlideLayout>().theme->GetFillStyle(style->fillRef.idx.get_value_or(0), fill);
				else if(parentFileIs<PPTX::SlideMaster>())
					parentFileAs<PPTX::SlideMaster>().theme->GetFillStyle(style->fillRef.idx.get_value_or(0), fill);

				if (style->fillRef.Color.is_init())
				{
					if (fill.is<PPTX::Logic::SolidFill>())
					{
						fill.as<PPTX::Logic::SolidFill>().Color = style->fillRef.Color;
					}
				}
				BGRA = style->fillRef.Color.GetBGRA();
			}

			if(spPr.Fill.is_init())
				spPr.Fill.Merge(fill);

			//if((!fill.is_init()) && (bMergeWithLevelUp))
			//{
			//	FillLevelUp();
			//	if(levelUp != NULL)
			//		BGRA = levelUp->GetFill(fill);
			//}

			return BGRA;
		}

		DWORD Shape::GetLine(Ln& line)const
		{
			DWORD BGRA = 0;
			//line.SetParentFilePointer(*parentFile);

			//if(bMergeWithLevelUp)
			//{
			//	FillLevelUp();
			//	if(levelUp != NULL)
			//		BGRA = levelUp->GetLine(line);
			//}
			if(style.IsInit())
			{
				if(parentFileIs<PPTX::Slide>())
					parentFileAs<PPTX::Slide>().theme->GetLineStyle(style->lnRef.idx.get_value_or(0), line);
				else if(parentFileIs<PPTX::SlideLayout>())
					parentFileAs<PPTX::SlideLayout>().theme->GetLineStyle(style->lnRef.idx.get_value_or(0), line);
				else if(parentFileIs<PPTX::SlideMaster>())
					parentFileAs<PPTX::SlideMaster>().theme->GetLineStyle(style->lnRef.idx.get_value_or(0), line);

				BGRA = style->lnRef.Color.GetBGRA();
			}

			if(spPr.ln.IsInit())
				spPr.ln->Merge(line);
			return BGRA;
		}

		void Shape::Merge(Shape& shape, bool bIsSlidePlaceholder)const
		{
			shape.nvSpPr = nvSpPr;
			spPr.Merge(shape.spPr);
			if(style.is_init())
			{
				shape.isFontRefInSlide = bIsSlidePlaceholder;
				shape.style = style;
				shape.style->SetParentFilePointer(parentFile);
			}
			if (!bIsSlidePlaceholder)
			{
				if(txBody.IsInit())
					txBody->Merge(shape.txBody);
			}
			else
			{
				if (txBody.is_init())
				{				
					if(!shape.txBody.is_init())
						shape.txBody = new TxBody();
				
					if (txBody->bodyPr.IsInit())
						txBody->bodyPr->Merge(shape.txBody->bodyPr);
					
					if(txBody->lstStyle.is_init())
					{
						for (int i = 0; i < 10; i++)
							if(txBody->lstStyle->levels[i].is_init())
								txBody->lstStyle->levels[i]->Merge(body[i]);
					}
				}
			}
		}

		void Shape::GetShapeFullDescription(Shape& shape, int level)const
		{
			if(level == 0)
				//shape.SetParentFilePointer(*parentFile);
				shape.SetParentPointer(parentElement);

			if(!nvSpPr.nvPr.ph.is_init())
			{
				Merge(shape);
				return;
			}
			if(parentFileIs<PPTX::SlideMaster>())
			{
				Merge(shape);
				return;
			}
			if(parentFileIs<PPTX::SlideLayout>())
			{
				FillLevelUp();
				if(levelUp != NULL)
					levelUp->GetShapeFullDescription(shape, level + 1);
				Merge(shape);
				return;
			}
			if(parentFileIs<PPTX::Slide>())
			{
				FillLevelUp();
				if(levelUp != NULL)
					levelUp->GetShapeFullDescription(shape, level + 1);
				Merge(shape, true);
				return;
			}
		}

		void Shape::toXmlWriterVML(NSBinPptxRW::CXmlWriter *pWriter, NSCommon::smart_ptr<PPTX::WrapperFile>& oTheme, NSCommon::smart_ptr<PPTX::WrapperWritingElement>& oClrMap, bool in_group)
		{
			std::wstring strPath, strTextRect;
			bool bOle = false;
			SimpleTypes::Vml::SptType vmlPrst = SimpleTypes::Vml::sptNotPrimitive;

			LONG lW = 43200, lH = 43200;
			int dL = 0, dT = 0, dW = 0, dH = 0;
			
			if (spPr.Geometry.is<PrstGeom>())
			{
				const PPTX::Logic::PrstGeom & lpGeom = spPr.Geometry.as<PPTX::Logic::PrstGeom>();
				
				SimpleTypes::CShapeType<> ooxPrst = SimpleTypes::CShapeType<>(lpGeom.prst.get());
				vmlPrst =  OOX::PrstGeom2VmlShapeType( ooxPrst.GetValue());
			}   

			if (spPr.xfrm.is_init())
			{
				if (spPr.xfrm->offX.is_init())	dL = *spPr.xfrm->offX;
				if (spPr.xfrm->offY.is_init())	dT = *spPr.xfrm->offY;
				if (spPr.xfrm->extX.is_init())	dW = *spPr.xfrm->extX;
				if (spPr.xfrm->extY.is_init())	dH = *spPr.xfrm->extY;

				lW = spPr.xfrm->extX.get_value_or(43200);
				lH = spPr.xfrm->extY.get_value_or(43200);
			}

			spPr.Geometry.ConvertToCustomVML(pWriter->m_pOOXToVMLRenderer, strPath, strTextRect, lW, lH);

            std::wstring strId		= L"shape " + std::to_wstring(pWriter->m_lObjectIdVML);
            std::wstring strSpid	= L"_x" + std::to_wstring(0xFFFF & (pWriter->m_lObjectIdVML >> 16)) + L"_s" + std::to_wstring(0xFFFF & pWriter->m_lObjectIdVML);
			pWriter->m_lObjectIdVML++;

            std::wstring strFillAttr;
            std::wstring strStrokeAttr;
            std::wstring strFillNode;
            std::wstring strStrokeNode;;

			CalculateFill(spPr, style, oTheme, oClrMap, strFillAttr, strFillNode, bOle);
			CalculateLine(spPr, style, oTheme, oClrMap, strStrokeAttr, strStrokeNode, bOle);

			pWriter->StartNode(L"v:shape");

			pWriter->StartAttributes();

            pWriter->WriteAttribute(L"id",		strId);
            pWriter->WriteAttribute(L"o:spid",	strSpid);

			if (vmlPrst != SimpleTypes::Vml::sptNotPrimitive)
				pWriter->WriteAttribute(L"o:spt", (int)vmlPrst);

			NSBinPptxRW::CXmlWriter oStylesWriter;
			if (pWriter->m_strStyleMain.empty())
			{
				oStylesWriter.WriteAttributeCSS(L"position", L"absolute");
				if (in_group)
				{
					oStylesWriter.WriteAttributeCSS_int(L"left",	dL / 100);
					oStylesWriter.WriteAttributeCSS_int(L"top",		dT / 100);
					oStylesWriter.WriteAttributeCSS_int(L"width",	dW / 100);
					oStylesWriter.WriteAttributeCSS_int(L"height",	dH / 100);
				}
				else
				{
					oStylesWriter.WriteAttributeCSS_int_pt(L"left",		dL / 12700);
					oStylesWriter.WriteAttributeCSS_int_pt(L"top",		dT / 12700);
					oStylesWriter.WriteAttributeCSS_int_pt(L"width",	dW / 12700);
					oStylesWriter.WriteAttributeCSS_int_pt(L"height",	dH / 12700);
				}
			}
			if (spPr.xfrm.is_init())
			{
				if (spPr.xfrm->rot.is_init())
				{
					int nRot = (int)((double)(*(spPr.xfrm->rot)) / 60000.0);
					oStylesWriter.WriteAttributeCSS_int(L"rotation", nRot);
				}
				bool bIsFH = spPr.xfrm->flipH.get_value_or(false);
				bool bIsFV = spPr.xfrm->flipV.get_value_or(false);
				if (bIsFH && bIsFV)
				{
					oStylesWriter.WriteAttributeCSS(L"flip", L"xy");
				}
				else if (bIsFH)
				{
					oStylesWriter.WriteAttributeCSS(L"flip", L"x");
				}
				else if (bIsFV)
				{
					oStylesWriter.WriteAttributeCSS(L"flip", L"y");
				}
			}

			if (txBody.is_init())
			{
				if (txBody->bodyPr.IsInit() && txBody->bodyPr->anchor.is_init())
				{
					std::wstring _strAnchor = txBody->bodyPr->anchor->get();
					if (_strAnchor == L"t")
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"top");
					else if (_strAnchor == L"b")
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"bottom");
					else if (_strAnchor == L"ctr")
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"middle");
				}
			}
			else if (TextBoxBodyPr.is_init())
			{
				if (TextBoxBodyPr->anchor.is_init())
				{
					std::wstring _strAnchor = TextBoxBodyPr->anchor->get();
					if (_strAnchor == L"t")
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"top");
					else if (_strAnchor == L"b")
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"bottom");
					else if (_strAnchor == _T("ctr"))
						oStylesWriter.WriteAttributeCSS(L"v-text-anchor", L"middle");
				}
			}

			pWriter->WriteAttribute(L"style", pWriter->m_strStyleMain + oStylesWriter.GetXmlString());

			if(!bOle)
			{
				//oStylesWriter.ClearNoAttack();
				//oStylesWriter.m_oWriter.AddSize(30);
				//oStylesWriter.m_oWriter.AddIntNoCheck(dW / 100);
				//oStylesWriter.m_oWriter.AddCharNoCheck(WCHAR(','));
				//oStylesWriter.m_oWriter.AddIntNoCheck(dH / 100);
				//pWriter->WriteAttribute(L"coordsize", oStylesWriter.GetXmlString());
				pWriter->WriteAttribute(L"coordsize", L"100000,100000");

				pWriter->WriteAttribute(L"path", strPath);
			}

			if (!pWriter->m_strAttributesMain.empty())
			{
				pWriter->WriteString(pWriter->m_strAttributesMain);
				pWriter->m_strAttributesMain.clear();
			}

			pWriter->WriteString(strFillAttr);
			pWriter->WriteString(strStrokeAttr);

			pWriter->EndAttributes();

			pWriter->StartNode(L"v:path");
			pWriter->StartAttributes();
			pWriter->WriteAttribute(L"textboxrect", strTextRect);
			pWriter->EndAttributes();
			pWriter->EndNode(L"v:path");

			pWriter->WriteString(strFillNode);
			pWriter->WriteString(strStrokeNode);
			
			pWriter->WriteString(pWriter->m_strNodes);
			pWriter->m_strNodes.clear();

			if (TextBoxShape.is_init())
			{
				pWriter->StartNode(L"v:textbox");
				pWriter->EndAttributes();
				pWriter->WriteString(*TextBoxShape);
				pWriter->EndNode(L"v:textbox");
			}

			pWriter->EndNode(L"v:shape");

			pWriter->m_strStyleMain.clear();
		}
		void Shape::toXmlWriterVMLBackground(NSBinPptxRW::CXmlWriter *pWriter, NSCommon::smart_ptr<PPTX::WrapperFile>& oTheme, NSCommon::smart_ptr<PPTX::WrapperWritingElement>& oClrMap)
		{
			std::wstring strFillAttr, strFillNode;
			CalculateFill(spPr, style, oTheme, oClrMap, strFillAttr, strFillNode, false);

			pWriter->StartNode(L"v:background");

			pWriter->StartAttributes();

			pWriter->WriteString(L" id=\"_x0000_s1025\"");

			if (!pWriter->m_strAttributesMain.empty())
			{
				pWriter->WriteString(pWriter->m_strAttributesMain);
				pWriter->m_strAttributesMain.clear();
			}

			pWriter->WriteString(strFillAttr);

			pWriter->EndAttributes();

			pWriter->WriteString(strFillNode);

			pWriter->EndNode(L"v:background");
		}
	} // namespace Logic
} // namespace PPTX
