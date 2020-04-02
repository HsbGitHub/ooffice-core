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
#ifndef PPTX_SHOWPR_BROWSE_INCLUDE_H_
#define PPTX_SHOWPR_BROWSE_INCLUDE_H_

#include "./../WrapperWritingElement.h"

namespace PPTX
{
	namespace nsShowPr
	{
		class Browse : public WrapperWritingElement
		{
		public:
			PPTX_LOGIC_BASE(Browse)

		public:
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				node.ReadAttributeBase(_T("showScrollbar"), showScrollbar);
			}
			virtual std::wstring toXML() const
			{
				XmlUtils::CAttribute oAttr;
				oAttr.Write(_T("showScrollbar"), showScrollbar);

				return XmlUtils::CreateNode(_T("p:browse"), oAttr);
			}

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
			{
				pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeStart);
				pWriter->WriteBool2(0, showScrollbar);
				pWriter->WriteBYTE(NSBinPptxRW::g_nodeAttributeEnd);
			}
			virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
			{
				pWriter->StartNode(_T("p:browse"));

				pWriter->StartAttributes();

				pWriter->WriteAttribute(_T("showScrollbar"), showScrollbar);

				pWriter->EndAttributes();	

				pWriter->EndNode(_T("p:browse"));
			}
			virtual void fromPPTY(NSBinPptxRW::CBinaryFileReader* pReader)
			{
				LONG _end_rec = pReader->GetPos() + pReader->GetLong() + 4;

				pReader->Skip(1); // start attributes

				while (true)
				{
					BYTE _at = pReader->GetUChar_TypeNode();
					if (_at == NSBinPptxRW::g_nodeAttributeEnd)
						break;

					if (0 == _at)
						showScrollbar = pReader->GetBool();
					else
						break;
				}

				pReader->Seek(_end_rec);
			}
		public:
			nullable_bool			showScrollbar;
		protected:
			virtual void FillParentPointersForChilds(){};
		};
	} // namespace nsShowPr
} // namespace PPTX

#endif // PPTX_SHOWPR_BROWSE_INCLUDE_H_