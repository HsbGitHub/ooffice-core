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
#ifndef PPTX_LOGIC_LIGHTRIG_INCLUDE_H_
#define PPTX_LOGIC_LIGHTRIG_INCLUDE_H_

#include "./../WrapperWritingElement.h"
#include "Rot.h"
#include "./../Limit/LightRigType.h"
#include "./../Limit/RectAlign.h"

namespace PPTX
{
	namespace Logic
	{

		class LightRig : public WrapperWritingElement
		{
		public:
			WritingElement_AdditionConstructors(LightRig)
			PPTX_LOGIC_BASE2(LightRig)

			virtual OOX::EElementType getType() const
			{
				return OOX::et_a_lightRig;
			}	
			void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				ReadAttributes( oReader );

				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring strName = oReader.GetName();

					if (strName == L"a:rot")
					{
						rot = oReader;
						break;
					}
				}
				FillParentPointersForChilds();
			}
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
				WritingElement_ReadAttributes_Start_No_NS( oReader )
					WritingElement_ReadAttributes_Read_if		( oReader, _T("dir"), dir)
					WritingElement_ReadAttributes_Read_else_if	( oReader, _T("rig"), rig)
				WritingElement_ReadAttributes_End( oReader )
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				dir = node.GetAttribute(_T("dir"));
				rig = node.GetAttribute(_T("rig"));

                rot = node.ReadNode(L"a:rot");
				FillParentPointersForChilds();
			}
			virtual std::wstring toXML() const
			{
				XmlUtils::CAttribute oAttr;
				oAttr.Write(_T("dir"), dir.get());
				oAttr.Write(_T("rig"), rig.get());

				XmlUtils::CNodeValue oValue;
				oValue.WriteNullable(rot);

				return XmlUtils::CreateNode(_T("a:lightRig"), oAttr, oValue);
			}
		public:
			nullable<Rot>		rot;

			Limit::RectAlign	dir;
			Limit::LightRigType rig;
		protected:
			virtual void FillParentPointersForChilds()
			{
				if(rot.IsInit())
					rot->SetParentPointer(this);
			}
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_LIGHTRIG_INCLUDE_H_