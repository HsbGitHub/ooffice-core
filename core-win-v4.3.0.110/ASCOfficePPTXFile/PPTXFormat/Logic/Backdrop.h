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
#ifndef PPTX_LOGIC_BACKDROP_INCLUDE_H_
#define PPTX_LOGIC_BACKDROP_INCLUDE_H_

#include "./../WrapperWritingElement.h"

namespace PPTX
{
	namespace Logic
	{

		class Backdrop : public WrapperWritingElement
		{
		public:
			WritingElement_AdditionConstructors(Backdrop)
			PPTX_LOGIC_BASE2(Backdrop)

			virtual OOX::EElementType getType() const
			{
				return OOX::et_a_backdrop;
			}	
			void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring strName = oReader.GetName();
					nullable_int x, y, z;

					if (strName == L"a:anchor")
					{
						ReadAttributes(oReader, x, y, z);
						anchorX = x.get_value_or(0);
						anchorY = y.get_value_or(0);
						anchorZ = z.get_value_or(0);
					}
					else if (strName == L"a:norm")
					{
						ReadAttributes(oReader, x, y, z);
						normX = x.get_value_or(0);
						normY = y.get_value_or(0);
						normZ = z.get_value_or(0);
					}
					else if (strName == L"a:up")
					{
						ReadAttributes(oReader, x, y, z);
						
						upX = x.get_value_or(0);
						upY = y.get_value_or(0);
						upZ = z.get_value_or(0);
					}
				}
				FillParentPointersForChilds();
			}
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader, nullable_int & x, nullable_int & y, nullable_int & z )
			{
				WritingElement_ReadAttributes_Start_No_NS( oReader )
					WritingElement_ReadAttributes_Read_if		( oReader, _T("x"), x)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("y"), y)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("z"), z)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("dx"), x)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("dy"), y)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("dz"), z)
				WritingElement_ReadAttributes_End( oReader )
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				XmlUtils::CXmlNode oNodeA = node.ReadNode(_T("a:anchor"));
				XmlUtils::CXmlNode oNodeN = node.ReadNode(_T("a:norm"));
				XmlUtils::CXmlNode oNodeU = node.ReadNode(_T("a:up"));
				
				anchorX = oNodeA.ReadAttributeInt(L"x");
				anchorY = oNodeA.ReadAttributeInt(L"y");
				anchorZ = oNodeA.ReadAttributeInt(L"z");

				normX = oNodeN.ReadAttributeInt(L"dx");
				normY = oNodeN.ReadAttributeInt(L"dy");
				normZ = oNodeN.ReadAttributeInt(L"dz");

				upX = oNodeU.ReadAttributeInt(L"dx");
				upY = oNodeU.ReadAttributeInt(L"dy");
				upZ = oNodeU.ReadAttributeInt(L"dz");
			}

			virtual std::wstring toXML() const
			{
                std::wstring str1 = L"<a:anchor x=\"" + std::to_wstring(anchorX) + L"\" y=\"" + std::to_wstring(anchorY) + L"\" z=\"" + std::to_wstring(anchorZ) + L"\"/>";

                std::wstring str2 = L"<a:norm dx=\"" + std::to_wstring(normX) + L"\" dy=\"" + std::to_wstring(normY) + L"\" dz=\"" + std::to_wstring(normY) + L"\"/>";

                std::wstring str3 = L"<a:up dx=\"" + std::to_wstring(upX) + L"\" dy=\"" + std::to_wstring(upY) + L"\" dz=\"" + std::to_wstring(upZ) + L"\"/>";

				return _T("<a:backdrop>") + str1 + str2 + str3 + _T("</a:backdrop>");
			}
		public:
			int anchorX;
			int anchorY;
			int anchorZ;

			int normX;
			int normY;
			int normZ;

			int upX;
			int upY;
			int upZ;
		protected:
			virtual void FillParentPointersForChilds(){};
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_BACKDROP_INCLUDE_H_
