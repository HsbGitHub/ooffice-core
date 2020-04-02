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
#pragma once
#ifndef OOX_CELLANCHOR_FILE_INCLUDE_H_
#define OOX_CELLANCHOR_FILE_INCLUDE_H_

#include "../CommonInclude.h"

#include "FromTo.h"
#include "Pic.h"
#include "Pos.h"
#include "Shape.h"

#include "Shape.h"

#include "../../../../../ASCOfficePPTXFile/PPTXFormat/Logic/GraphicFrame.h"

namespace OOX
{
	namespace Spreadsheet
	{
		class CCellAnchor : public WritingElement
		{
		public:
			WritingElementSpreadsheet_AdditionConstructors(CCellAnchor)
            CCellAnchor(const SimpleTypes::Spreadsheet::CCellAnchorType<>& oAnchorType/* = SimpleTypes::Spreadsheet::CCellAnchorType<>()*/):m_oAnchorType(oAnchorType)
			{
			}
			virtual ~CCellAnchor()
			{
			}

		public:
            virtual std::wstring toXML() const
			{
				return _T("");
			}
			virtual void toXML(NSStringUtils::CStringBuilder& writer) const
			{
				if(isValid())
				{
					if(m_oAlternateContent.IsInit() && m_oAlternateContent->ToBool())
					{
						writer.WriteString(L"<mc:AlternateContent xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\"><mc:Choice xmlns:a14=\"http://schemas.microsoft.com/office/drawing/2010/main\" Requires=\"a14\">");
					}
					std::wstring sStart;
					std::wstring sEnd;
					if(m_oFrom.IsInit() && m_oTo.IsInit())
					{
						sStart	= _T("<xdr:twoCellAnchor editAs=\"") + m_oAnchorType.ToString() + _T("\">");
						sEnd	= _T("</xdr:twoCellAnchor>");
						
						writer.WriteString(sStart);
						if(m_oFrom.IsInit())
							m_oFrom->toXML2(writer, _T("xdr:from"));
						if(m_oTo.IsInit())
							m_oTo->toXML2(writer, _T("xdr:to"));
					}
					else if(m_oFrom.IsInit() && m_oExt.IsInit())
					{
						sStart.append(_T("<xdr:oneCellAnchor>"));
						sEnd = _T("</xdr:oneCellAnchor>");
						writer.WriteString(sStart);
						if(m_oFrom.IsInit())
							m_oFrom->toXML2(writer, _T("xdr:from"));
						if(m_oExt.IsInit())
							m_oExt->toXML(writer);
					}
					else
					{
						sStart.append(_T("<xdr:absoluteAnchor>"));
						sEnd = _T("</xdr:absoluteAnchor>");
						writer.WriteString(sStart);
						if(m_oPos.IsInit())
						m_oPos->toXML(writer);
						if(m_oExt.IsInit())
							m_oExt->toXML(writer);
					}
					if(m_oXml.IsInit())
						writer.WriteString(m_oXml.get());	
					if(m_oGraphicFrame.IsInit())
						writer.WriteString(m_oGraphicFrame->toXML());
					writer.WriteString(sEnd);

					if(m_oAlternateContent.IsInit() && m_oAlternateContent->ToBool())
					{
						writer.WriteString(L"</mc:Choice><mc:Fallback/></mc:AlternateContent>");
					}
				}
			}
			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				ReadAttributes( oReader );

				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring sName = XmlUtils::GetNameNoNS(oReader.GetName());

					if ( _T("from") == sName )
						m_oFrom = oReader;
					else if ( _T("to") == sName )
						m_oTo = oReader;
					else if ( _T("pos") == sName )
						m_oPos = oReader;
					else if ( _T("ext") == sName )
						m_oExt = oReader;
					else if ( _T("graphicFrame") == sName )
					{
						m_oGraphicFrame = oReader;
						if ((m_oGraphicFrame.IsInit())  &&	(m_oGraphicFrame->spid.IsInit()))
						{
							//вытащим выше ссылку на объект (для удобства)
							m_sSpId = m_oGraphicFrame->spid.get();
						}
					}
	//Так читать правильнее ... но для совместимости нужно хранить и все xml !!!!
					//else if (_T("pic") == sName )
					//	m_oPicture = oReader;
					//else if (_T("sp") == sName)
					//	m_oShape = oReader;
					//else if (_T("cxnSp") == sName)
					//	m_oConnShape = oReader;
					//else if (_T("grpSp") == sName || _T("AlternateContent") == sName)
					//	m_oXml = oReader.GetOuterXml();
/////////////////////////////////
					//
					else if ( _T("pic") == sName || _T("sp") == sName || _T("grpSp") == sName || _T("cxnSp") == sName)
					{			
						m_oXml = oReader.GetOuterXml();
						{
							XmlUtils::CXmlLiteReader oShapeReader;
							//сформируем полноценную xml-строку
                            std::wstring xmlString;// = L"<?xml version=\"1.0\"?>";// encoding=\"UTF-8\"
							xmlString += L"<root ";
								xmlString += L"xmlns:a=\"http://schemas.openxmlformats.org/drawingml/2006/main\" ";
								xmlString += L"xmlns:a14=\"http://schemas.microsoft.com/office/drawing/2010/main\" ";	
								xmlString += L"xmlns:xdr=\"http://schemas.openxmlformats.org/drawingml/2006/spreadsheetDrawing\" ";
								xmlString += L"xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" ";
							xmlString += L">";
							xmlString += m_oXml->c_str();
							xmlString += L"</root>";
                                                        bool result =oShapeReader.FromString(xmlString);

							result = oShapeReader.ReadNextNode();//root
							result = oShapeReader.ReadNextNode();

							std::wstring sName = XmlUtils::GetNameNoNS(oShapeReader.GetName());
							
							if (_T("pic") == sName)
								m_oPicture = oShapeReader;
							else if (_T("sp") == sName)
							{	//тут может быть не полноценный объект, а ссылка на него, следовательно и xml что выше для
								// pptx:DrawingObjectConverter будет не правильная - сотрем ее
								m_oShape = oShapeReader;
								if ((m_oShape.IsInit()) && (m_oShape->m_oNvSpPr.IsInit()) && 
									(m_oShape->m_oNvSpPr->m_oCNvPr.IsInit()) && (m_oShape->m_oNvSpPr->m_oCNvPr->m_oExtLst.IsInit()))
								{
									for (size_t i=0; i < m_oShape->m_oNvSpPr->m_oCNvPr->m_oExtLst->m_arrExt.size();i++)
									{
										OOX::Drawing::COfficeArtExtension* pExt = m_oShape->m_oNvSpPr->m_oCNvPr->m_oExtLst->m_arrExt[i];
										if (pExt->m_oCompatExt.IsInit() && pExt->m_oCompatExt->m_sSpId.IsInit())
										{
											//собственно это и есть ссылка на обеъект -> переложим ее "повыше" (для удобства)
											m_oXml.reset();
											m_sSpId = pExt->m_oCompatExt->m_sSpId.get();
										}
									}
								}
							}
							else if (_T("cxnSp") == sName)
								m_oConnShape = oShapeReader;
							else if (_T("grpSp") == sName)
								m_oGroupShape = oShapeReader;
						}
					}
					else if ( _T("AlternateContent") == sName)
					{			
						//Demo-2010WinterOlympics2.xlsx
						//вариативность на разные версии офиса части параметров - кстати ... это может встретиться в ЛЮБОМ месте 
						//todooo сделать чтение не обязательно fallback, по выбору версии нужной нам (a14, ..)
						{
							nCurDepth++;
							while( oReader.ReadNextSiblingNode( nCurDepth ) )
							{
								std::wstring sName = XmlUtils::GetNameNoNS(oReader.GetName());
								if ( _T("Fallback") == sName || _T("Choice") == sName )
								{
                                    std::wstring sRequires;
									ReadAttributesRequire(oReader, sRequires);
                                    std::wstring xmlString;// = L"<?xml version=\"1.0\"?>"; //encoding=\"UTF-8\"
									xmlString += L"<root ";
										xmlString += L"xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\" ";
										xmlString += L"xmlns:a=\"http://schemas.openxmlformats.org/drawingml/2006/main\" ";
										xmlString += L"xmlns:a14=\"http://schemas.microsoft.com/office/drawing/2010/main\" ";	
										xmlString += L"xmlns:xdr=\"http://schemas.openxmlformats.org/drawingml/2006/spreadsheetDrawing\" ";
										xmlString += L"xmlns:r=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships\" ";
									xmlString += L">";
									xmlString += oReader.GetOuterXml();
									xmlString += L"</root>";

									//todo better check (a14 can be math, slicer)
                                    if(_T("Choice") == sName && !(L"a14" == sRequires && -1 != xmlString.find(L"a14:m")))
									{
										continue;
									}
									XmlUtils::CXmlLiteReader oSubReader;
									
									if (oSubReader.FromString(xmlString))
									{
										oSubReader.ReadNextNode();//root

										oSubReader.ReadNextNode();//fallback
										fromXML(oSubReader);	
									}
									break;
								}
							}
							nCurDepth--;
						}
					}
				}
			}

			virtual EElementType getType () const
			{
				return et_CellAnchor;
			}

			virtual void setAnchorType (SimpleTypes::Spreadsheet::ECellAnchorType eType)
			{
				m_oAnchorType.SetValue(eType);
			}
			virtual SimpleTypes::Spreadsheet::ECellAnchorType getAnchorType () const
			{
				return m_oAnchorType.GetValue();
			}
			bool isValid() const
			{
				SimpleTypes::Spreadsheet::ECellAnchorType eAnchorType = m_oAnchorType.GetValue();
				if(!((m_oFrom.IsInit() && m_oTo.IsInit()) || (m_oFrom.IsInit() && m_oExt.IsInit()) || (m_oPos.IsInit() && m_oExt.IsInit())))
					return false;
				if(false == m_oXml.IsInit() && false == m_oGraphicFrame.IsInit() && false == m_sSpId.IsInit())
					return false;
				return true;
			}
		private:
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
			}
            void ReadAttributesRequire(XmlUtils::CXmlLiteReader& oReader, std::wstring& sRequire)
			{
				// Читаем атрибуты
				WritingElement_ReadAttributes_Start( oReader )
				WritingElement_ReadAttributes_ReadSingle( oReader, _T("Requires"),      sRequire )
				WritingElement_ReadAttributes_End( oReader )
			}
		public:
			SimpleTypes::Spreadsheet::CCellAnchorType<>		m_oAnchorType;
			nullable<OOX::Spreadsheet::CFromTo>				m_oFrom;
			nullable<OOX::Spreadsheet::CFromTo>				m_oTo;
			nullable<OOX::Spreadsheet::CPos>				m_oPos;
			nullable<OOX::Spreadsheet::CExt>				m_oExt;
			nullable<PPTX::Logic::GraphicFrame>				m_oGraphicFrame;
			nullable<OOX::Spreadsheet::CPic>				m_oPicture;
			nullable<OOX::Spreadsheet::CGroupShape>			m_oGroupShape;
			nullable<OOX::Spreadsheet::CShape>				m_oShape;
			nullable<OOX::Spreadsheet::CConnShape>			m_oConnShape;

			// для pptx:ObjectDrawingConverter
			nullable<std::wstring>							m_oXml;
			nullable<SimpleTypes::COnOff<>>					m_oAlternateContent;

			//для удобства
			nullable<std::wstring>							m_sSpId;
		};
	} //Spreadsheet
} // namespace OOX

#endif // OOX_CELLANCHOR_FILE_INCLUDE_H_
