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
#ifndef PPTX_LOGIC_SCENE3D_INCLUDE_H_
#define PPTX_LOGIC_SCENE3D_INCLUDE_H_

#include "./../WrapperWritingElement.h"
#include "Camera.h"
#include "LightRig.h"
#include "Backdrop.h"

namespace PPTX
{
	namespace Logic
	{

		class Scene3d : public WrapperWritingElement
		{
		public:
			WritingElement_AdditionConstructors(Scene3d)
			PPTX_LOGIC_BASE2(Scene3d)

			virtual OOX::EElementType getType() const
			{
				return OOX::et_a_scene3d;
			}	
			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring strName = oReader.GetName();

					if (strName == L"a:camera")
						camera = oReader;
                	if (strName == L"a:lightRig")
						lightRig = oReader;
                	if (strName == L"a:backdrop")
						backdrop = oReader;
				}
				FillParentPointersForChilds();
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
                camera		= node.ReadNode(L"a:camera");
                lightRig	= node.ReadNode(L"a:lightRig");
                backdrop	= node.ReadNode(L"a:backdrop");
				
				FillParentPointersForChilds();
			}
			virtual std::wstring toXML() const
			{
				XmlUtils::CNodeValue oValue;
				oValue.Write(camera);
				oValue.Write(lightRig);
				oValue.WriteNullable(backdrop);

				return XmlUtils::CreateNode(_T("a:scene3d"), oValue);
			}

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
			{
				// TODO:
			}

			virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
			{
				// TODO:	
			}

		public:
			Camera				camera;
			LightRig			lightRig;
			nullable<Backdrop>	backdrop;
		protected:
			virtual void FillParentPointersForChilds()
			{
				camera.SetParentPointer(this);
				lightRig.SetParentPointer(this);
				if(backdrop.IsInit())
					backdrop->SetParentPointer(this);
			}
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_SCENE3D_INCLUDE_H_
