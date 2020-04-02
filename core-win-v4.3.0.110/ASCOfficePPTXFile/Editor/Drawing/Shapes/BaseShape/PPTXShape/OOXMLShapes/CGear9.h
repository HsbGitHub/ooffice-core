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
#include "../PPTXShape.h"

namespace OOXMLShapes
{
	class CGear9 : public CPPTXShape
	{
		public:
			CGear9()
			{
				LoadFromXML(
					_T("<ooxml-shape>")
					_T("<avLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"adj1\" fmla=\"val 10000\" />")
					  _T("<gd name=\"adj2\" fmla=\"val 1763\" />")
					_T("</avLst>")
					_T("<gdLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<gd name=\"a1\" fmla=\"pin 0 adj1 20000\" />")
					  _T("<gd name=\"a2\" fmla=\"pin 0 adj2 2679\" />")
					  _T("<gd name=\"th\" fmla=\"*/ ss a1 100000\" />")
					  _T("<gd name=\"lFD\" fmla=\"*/ ss a2 100000\" />")
					  _T("<gd name=\"th2\" fmla=\"*/ th 1 2\" />")
					  _T("<gd name=\"l2\" fmla=\"*/ lFD 1 2\" />")
					  _T("<gd name=\"l3\" fmla=\"+- th2 l2 0\" />")
					  _T("<gd name=\"rh\" fmla=\"+- hd2 0 th\" />")
					  _T("<gd name=\"rw\" fmla=\"+- wd2 0 th\" />")
					  _T("<gd name=\"dr\" fmla=\"+- rw 0 rh\" />")
					  _T("<gd name=\"maxr\" fmla=\"?: dr rh rw\" />")
					  _T("<gd name=\"ha\" fmla=\"at2 maxr l3\" />")
					  _T("<gd name=\"aA1\" fmla=\"+- 18600000 0 ha\" />")
					  _T("<gd name=\"aD1\" fmla=\"+- 18600000 ha 0\" />")
					  _T("<gd name=\"ta11\" fmla=\"cos rw aA1\" />")
					  _T("<gd name=\"ta12\" fmla=\"sin rh aA1\" />")
					  _T("<gd name=\"bA1\" fmla=\"at2 ta11 ta12\" />")
					  _T("<gd name=\"cta1\" fmla=\"cos rh bA1\" />")
					  _T("<gd name=\"sta1\" fmla=\"sin rw bA1\" />")
					  _T("<gd name=\"ma1\" fmla=\"mod cta1 sta1 0\" />")
					  _T("<gd name=\"na1\" fmla=\"*/ rw rh ma1\" />")
					  _T("<gd name=\"dxa1\" fmla=\"cos na1 bA1\" />")
					  _T("<gd name=\"dya1\" fmla=\"sin na1 bA1\" />")
					  _T("<gd name=\"xA1\" fmla=\"+- hc dxa1 0\" />")
					  _T("<gd name=\"yA1\" fmla=\"+- vc dya1 0\" />")
					  _T("<gd name=\"td11\" fmla=\"cos rw aD1\" />")
					  _T("<gd name=\"td12\" fmla=\"sin rh aD1\" />")
					  _T("<gd name=\"bD1\" fmla=\"at2 td11 td12\" />")
					  _T("<gd name=\"ctd1\" fmla=\"cos rh bD1\" />")
					  _T("<gd name=\"std1\" fmla=\"sin rw bD1\" />")
					  _T("<gd name=\"md1\" fmla=\"mod ctd1 std1 0\" />")
					  _T("<gd name=\"nd1\" fmla=\"*/ rw rh md1\" />")
					  _T("<gd name=\"dxd1\" fmla=\"cos nd1 bD1\" />")
					  _T("<gd name=\"dyd1\" fmla=\"sin nd1 bD1\" />")
					  _T("<gd name=\"xD1\" fmla=\"+- hc dxd1 0\" />")
					  _T("<gd name=\"yD1\" fmla=\"+- vc dyd1 0\" />")
					  _T("<gd name=\"xAD1\" fmla=\"+- xA1 0 xD1\" />")
					  _T("<gd name=\"yAD1\" fmla=\"+- yA1 0 yD1\" />")
					  _T("<gd name=\"lAD1\" fmla=\"mod xAD1 yAD1 0\" />")
					  _T("<gd name=\"a12\" fmla=\"at2 yAD1 xAD1\" />")
					  _T("<gd name=\"dxF1\" fmla=\"sin lFD a12\" />")
					  _T("<gd name=\"dyF1\" fmla=\"cos lFD a12\" />")
					  _T("<gd name=\"xF1\" fmla=\"+- xD1 dxF1 0\" />")
					  _T("<gd name=\"yF1\" fmla=\"+- yD1 dyF1 0\" />")
					  _T("<gd name=\"xE1\" fmla=\"+- xA1 0 dxF1\" />")
					  _T("<gd name=\"yE1\" fmla=\"+- yA1 0 dyF1\" />")
					  _T("<gd name=\"yC1t\" fmla=\"sin th a12\" />")
					  _T("<gd name=\"xC1t\" fmla=\"cos th a12\" />")
					  _T("<gd name=\"yC1\" fmla=\"+- yF1 yC1t 0\" />")
					  _T("<gd name=\"xC1\" fmla=\"+- xF1 0 xC1t\" />")
					  _T("<gd name=\"yB1\" fmla=\"+- yE1 yC1t 0\" />")
					  _T("<gd name=\"xB1\" fmla=\"+- xE1 0 xC1t\" />")
					  _T("<gd name=\"aA2\" fmla=\"+- 21000000 0 ha\" />")
					  _T("<gd name=\"aD2\" fmla=\"+- 21000000 ha 0\" />")
					  _T("<gd name=\"ta21\" fmla=\"cos rw aA2\" />")
					  _T("<gd name=\"ta22\" fmla=\"sin rh aA2\" />")
					  _T("<gd name=\"bA2\" fmla=\"at2 ta21 ta22\" />")
					  _T("<gd name=\"cta2\" fmla=\"cos rh bA2\" />")
					  _T("<gd name=\"sta2\" fmla=\"sin rw bA2\" />")
					  _T("<gd name=\"ma2\" fmla=\"mod cta2 sta2 0\" />")
					  _T("<gd name=\"na2\" fmla=\"*/ rw rh ma2\" />")
					  _T("<gd name=\"dxa2\" fmla=\"cos na2 bA2\" />")
					  _T("<gd name=\"dya2\" fmla=\"sin na2 bA2\" />")
					  _T("<gd name=\"xA2\" fmla=\"+- hc dxa2 0\" />")
					  _T("<gd name=\"yA2\" fmla=\"+- vc dya2 0\" />")
					  _T("<gd name=\"td21\" fmla=\"cos rw aD2\" />")
					  _T("<gd name=\"td22\" fmla=\"sin rh aD2\" />")
					  _T("<gd name=\"bD2\" fmla=\"at2 td21 td22\" />")
					  _T("<gd name=\"ctd2\" fmla=\"cos rh bD2\" />")
					  _T("<gd name=\"std2\" fmla=\"sin rw bD2\" />")
					  _T("<gd name=\"md2\" fmla=\"mod ctd2 std2 0\" />")
					  _T("<gd name=\"nd2\" fmla=\"*/ rw rh md2\" />")
					  _T("<gd name=\"dxd2\" fmla=\"cos nd2 bD2\" />")
					  _T("<gd name=\"dyd2\" fmla=\"sin nd2 bD2\" />")
					  _T("<gd name=\"xD2\" fmla=\"+- hc dxd2 0\" />")
					  _T("<gd name=\"yD2\" fmla=\"+- vc dyd2 0\" />")
					  _T("<gd name=\"xAD2\" fmla=\"+- xA2 0 xD2\" />")
					  _T("<gd name=\"yAD2\" fmla=\"+- yA2 0 yD2\" />")
					  _T("<gd name=\"lAD2\" fmla=\"mod xAD2 yAD2 0\" />")
					  _T("<gd name=\"a22\" fmla=\"at2 yAD2 xAD2\" />")
					  _T("<gd name=\"dxF2\" fmla=\"sin lFD a22\" />")
					  _T("<gd name=\"dyF2\" fmla=\"cos lFD a22\" />")
					  _T("<gd name=\"xF2\" fmla=\"+- xD2 dxF2 0\" />")
					  _T("<gd name=\"yF2\" fmla=\"+- yD2 dyF2 0\" />")
					  _T("<gd name=\"xE2\" fmla=\"+- xA2 0 dxF2\" />")
					  _T("<gd name=\"yE2\" fmla=\"+- yA2 0 dyF2\" />")
					  _T("<gd name=\"yC2t\" fmla=\"sin th a22\" />")
					  _T("<gd name=\"xC2t\" fmla=\"cos th a22\" />")
					  _T("<gd name=\"yC2\" fmla=\"+- yF2 yC2t 0\" />")
					  _T("<gd name=\"xC2\" fmla=\"+- xF2 0 xC2t\" />")
					  _T("<gd name=\"yB2\" fmla=\"+- yE2 yC2t 0\" />")
					  _T("<gd name=\"xB2\" fmla=\"+- xE2 0 xC2t\" />")
					  _T("<gd name=\"swAng1\" fmla=\"+- bA2 0 bD1\" />")
					  _T("<gd name=\"aA3\" fmla=\"+- 1800000 0 ha\" />")
					  _T("<gd name=\"aD3\" fmla=\"+- 1800000 ha 0\" />")
					  _T("<gd name=\"ta31\" fmla=\"cos rw aA3\" />")
					  _T("<gd name=\"ta32\" fmla=\"sin rh aA3\" />")
					  _T("<gd name=\"bA3\" fmla=\"at2 ta31 ta32\" />")
					  _T("<gd name=\"cta3\" fmla=\"cos rh bA3\" />")
					  _T("<gd name=\"sta3\" fmla=\"sin rw bA3\" />")
					  _T("<gd name=\"ma3\" fmla=\"mod cta3 sta3 0\" />")
					  _T("<gd name=\"na3\" fmla=\"*/ rw rh ma3\" />")
					  _T("<gd name=\"dxa3\" fmla=\"cos na3 bA3\" />")
					  _T("<gd name=\"dya3\" fmla=\"sin na3 bA3\" />")
					  _T("<gd name=\"xA3\" fmla=\"+- hc dxa3 0\" />")
					  _T("<gd name=\"yA3\" fmla=\"+- vc dya3 0\" />")
					  _T("<gd name=\"td31\" fmla=\"cos rw aD3\" />")
					  _T("<gd name=\"td32\" fmla=\"sin rh aD3\" />")
					  _T("<gd name=\"bD3\" fmla=\"at2 td31 td32\" />")
					  _T("<gd name=\"ctd3\" fmla=\"cos rh bD3\" />")
					  _T("<gd name=\"std3\" fmla=\"sin rw bD3\" />")
					  _T("<gd name=\"md3\" fmla=\"mod ctd3 std3 0\" />")
					  _T("<gd name=\"nd3\" fmla=\"*/ rw rh md3\" />")
					  _T("<gd name=\"dxd3\" fmla=\"cos nd3 bD3\" />")
					  _T("<gd name=\"dyd3\" fmla=\"sin nd3 bD3\" />")
					  _T("<gd name=\"xD3\" fmla=\"+- hc dxd3 0\" />")
					  _T("<gd name=\"yD3\" fmla=\"+- vc dyd3 0\" />")
					  _T("<gd name=\"xAD3\" fmla=\"+- xA3 0 xD3\" />")
					  _T("<gd name=\"yAD3\" fmla=\"+- yA3 0 yD3\" />")
					  _T("<gd name=\"lAD3\" fmla=\"mod xAD3 yAD3 0\" />")
					  _T("<gd name=\"a3\" fmla=\"at2 yAD3 xAD3\" />")
					  _T("<gd name=\"dxF3\" fmla=\"sin lFD a3\" />")
					  _T("<gd name=\"dyF3\" fmla=\"cos lFD a3\" />")
					  _T("<gd name=\"xF3\" fmla=\"+- xD3 dxF3 0\" />")
					  _T("<gd name=\"yF3\" fmla=\"+- yD3 dyF3 0\" />")
					  _T("<gd name=\"xE3\" fmla=\"+- xA3 0 dxF3\" />")
					  _T("<gd name=\"yE3\" fmla=\"+- yA3 0 dyF3\" />")
					  _T("<gd name=\"yC3t\" fmla=\"sin th a3\" />")
					  _T("<gd name=\"xC3t\" fmla=\"cos th a3\" />")
					  _T("<gd name=\"yC3\" fmla=\"+- yF3 yC3t 0\" />")
					  _T("<gd name=\"xC3\" fmla=\"+- xF3 0 xC3t\" />")
					  _T("<gd name=\"yB3\" fmla=\"+- yE3 yC3t 0\" />")
					  _T("<gd name=\"xB3\" fmla=\"+- xE3 0 xC3t\" />")
					  _T("<gd name=\"swAng2\" fmla=\"+- bA3 0 bD2\" />")
					  _T("<gd name=\"aA4\" fmla=\"+- 4200000 0 ha\" />")
					  _T("<gd name=\"aD4\" fmla=\"+- 4200000 ha 0\" />")
					  _T("<gd name=\"ta41\" fmla=\"cos rw aA4\" />")
					  _T("<gd name=\"ta42\" fmla=\"sin rh aA4\" />")
					  _T("<gd name=\"bA4\" fmla=\"at2 ta41 ta42\" />")
					  _T("<gd name=\"cta4\" fmla=\"cos rh bA4\" />")
					  _T("<gd name=\"sta4\" fmla=\"sin rw bA4\" />")
					  _T("<gd name=\"ma4\" fmla=\"mod cta4 sta4 0\" />")
					  _T("<gd name=\"na4\" fmla=\"*/ rw rh ma4\" />")
					  _T("<gd name=\"dxa4\" fmla=\"cos na4 bA4\" />")
					  _T("<gd name=\"dya4\" fmla=\"sin na4 bA4\" />")
					  _T("<gd name=\"xA4\" fmla=\"+- hc dxa4 0\" />")
					  _T("<gd name=\"yA4\" fmla=\"+- vc dya4 0\" />")
					  _T("<gd name=\"td41\" fmla=\"cos rw aD4\" />")
					  _T("<gd name=\"td42\" fmla=\"sin rh aD4\" />")
					  _T("<gd name=\"bD4\" fmla=\"at2 td41 td42\" />")
					  _T("<gd name=\"ctd4\" fmla=\"cos rh bD4\" />")
					  _T("<gd name=\"std4\" fmla=\"sin rw bD4\" />")
					  _T("<gd name=\"md4\" fmla=\"mod ctd4 std4 0\" />")
					  _T("<gd name=\"nd4\" fmla=\"*/ rw rh md4\" />")
					  _T("<gd name=\"dxd4\" fmla=\"cos nd4 bD4\" />")
					  _T("<gd name=\"dyd4\" fmla=\"sin nd4 bD4\" />")
					  _T("<gd name=\"xD4\" fmla=\"+- hc dxd4 0\" />")
					  _T("<gd name=\"yD4\" fmla=\"+- vc dyd4 0\" />")
					  _T("<gd name=\"xAD4\" fmla=\"+- xA4 0 xD4\" />")
					  _T("<gd name=\"yAD4\" fmla=\"+- yA4 0 yD4\" />")
					  _T("<gd name=\"lAD4\" fmla=\"mod xAD4 yAD4 0\" />")
					  _T("<gd name=\"a4\" fmla=\"at2 yAD4 xAD4\" />")
					  _T("<gd name=\"dxF4\" fmla=\"sin lFD a4\" />")
					  _T("<gd name=\"dyF4\" fmla=\"cos lFD a4\" />")
					  _T("<gd name=\"xF4\" fmla=\"+- xD4 dxF4 0\" />")
					  _T("<gd name=\"yF4\" fmla=\"+- yD4 dyF4 0\" />")
					  _T("<gd name=\"xE4\" fmla=\"+- xA4 0 dxF4\" />")
					  _T("<gd name=\"yE4\" fmla=\"+- yA4 0 dyF4\" />")
					  _T("<gd name=\"yC4t\" fmla=\"sin th a4\" />")
					  _T("<gd name=\"xC4t\" fmla=\"cos th a4\" />")
					  _T("<gd name=\"yC4\" fmla=\"+- yF4 yC4t 0\" />")
					  _T("<gd name=\"xC4\" fmla=\"+- xF4 0 xC4t\" />")
					  _T("<gd name=\"yB4\" fmla=\"+- yE4 yC4t 0\" />")
					  _T("<gd name=\"xB4\" fmla=\"+- xE4 0 xC4t\" />")
					  _T("<gd name=\"swAng3\" fmla=\"+- bA4 0 bD3\" />")
					  _T("<gd name=\"aA5\" fmla=\"+- 6600000 0 ha\" />")
					  _T("<gd name=\"aD5\" fmla=\"+- 6600000 ha 0\" />")
					  _T("<gd name=\"ta51\" fmla=\"cos rw aA5\" />")
					  _T("<gd name=\"ta52\" fmla=\"sin rh aA5\" />")
					  _T("<gd name=\"bA5\" fmla=\"at2 ta51 ta52\" />")
					  _T("<gd name=\"td51\" fmla=\"cos rw aD5\" />")
					  _T("<gd name=\"td52\" fmla=\"sin rh aD5\" />")
					  _T("<gd name=\"bD5\" fmla=\"at2 td51 td52\" />")
					  _T("<gd name=\"xD5\" fmla=\"+- w 0 xA4\" />")
					  _T("<gd name=\"xC5\" fmla=\"+- w 0 xB4\" />")
					  _T("<gd name=\"xB5\" fmla=\"+- w 0 xC4\" />")
					  _T("<gd name=\"swAng4\" fmla=\"+- bA5 0 bD4\" />")
					  _T("<gd name=\"aD6\" fmla=\"+- 9000000 ha 0\" />")
					  _T("<gd name=\"td61\" fmla=\"cos rw aD6\" />")
					  _T("<gd name=\"td62\" fmla=\"sin rh aD6\" />")
					  _T("<gd name=\"bD6\" fmla=\"at2 td61 td62\" />")
					  _T("<gd name=\"xD6\" fmla=\"+- w 0 xA3\" />")
					  _T("<gd name=\"xC6\" fmla=\"+- w 0 xB3\" />")
					  _T("<gd name=\"xB6\" fmla=\"+- w 0 xC3\" />")
					  _T("<gd name=\"aD7\" fmla=\"+- 11400000 ha 0\" />")
					  _T("<gd name=\"td71\" fmla=\"cos rw aD7\" />")
					  _T("<gd name=\"td72\" fmla=\"sin rh aD7\" />")
					  _T("<gd name=\"bD7\" fmla=\"at2 td71 td72\" />")
					  _T("<gd name=\"xD7\" fmla=\"+- w 0 xA2\" />")
					  _T("<gd name=\"xC7\" fmla=\"+- w 0 xB2\" />")
					  _T("<gd name=\"xB7\" fmla=\"+- w 0 xC2\" />")
					  _T("<gd name=\"aD8\" fmla=\"+- 13800000 ha 0\" />")
					  _T("<gd name=\"td81\" fmla=\"cos rw aD8\" />")
					  _T("<gd name=\"td82\" fmla=\"sin rh aD8\" />")
					  _T("<gd name=\"bD8\" fmla=\"at2 td81 td82\" />")
					  _T("<gd name=\"xA8\" fmla=\"+- w 0 xD1\" />")
					  _T("<gd name=\"xD8\" fmla=\"+- w 0 xA1\" />")
					  _T("<gd name=\"xC8\" fmla=\"+- w 0 xB1\" />")
					  _T("<gd name=\"xB8\" fmla=\"+- w 0 xC1\" />")
					  _T("<gd name=\"aA9\" fmla=\"+- 3cd4 0 ha\" />")
					  _T("<gd name=\"aD9\" fmla=\"+- 3cd4 ha 0\" />")
					  _T("<gd name=\"td91\" fmla=\"cos rw aD9\" />")
					  _T("<gd name=\"td92\" fmla=\"sin rh aD9\" />")
					  _T("<gd name=\"bD9\" fmla=\"at2 td91 td92\" />")
					  _T("<gd name=\"ctd9\" fmla=\"cos rh bD9\" />")
					  _T("<gd name=\"std9\" fmla=\"sin rw bD9\" />")
					  _T("<gd name=\"md9\" fmla=\"mod ctd9 std9 0\" />")
					  _T("<gd name=\"nd9\" fmla=\"*/ rw rh md9\" />")
					  _T("<gd name=\"dxd9\" fmla=\"cos nd9 bD9\" />")
					  _T("<gd name=\"dyd9\" fmla=\"sin nd9 bD9\" />")
					  _T("<gd name=\"xD9\" fmla=\"+- hc dxd9 0\" />")
					  _T("<gd name=\"yD9\" fmla=\"+- vc dyd9 0\" />")
					  _T("<gd name=\"ta91\" fmla=\"cos rw aA9\" />")
					  _T("<gd name=\"ta92\" fmla=\"sin rh aA9\" />")
					  _T("<gd name=\"bA9\" fmla=\"at2 ta91 ta92\" />")
					  _T("<gd name=\"xA9\" fmla=\"+- hc 0 dxd9\" />")
					  _T("<gd name=\"xF9\" fmla=\"+- xD9 0 lFD\" />")
					  _T("<gd name=\"xE9\" fmla=\"+- xA9 lFD 0\" />")
					  _T("<gd name=\"yC9\" fmla=\"+- yD9 0 th\" />")
					  _T("<gd name=\"swAng5\" fmla=\"+- bA9 0 bD8\" />")
					  _T("<gd name=\"xCxn1\" fmla=\"+/ xB1 xC1 2\" />")
					  _T("<gd name=\"yCxn1\" fmla=\"+/ yB1 yC1 2\" />")
					  _T("<gd name=\"xCxn2\" fmla=\"+/ xB2 xC2 2\" />")
					  _T("<gd name=\"yCxn2\" fmla=\"+/ yB2 yC2 2\" />")
					  _T("<gd name=\"xCxn3\" fmla=\"+/ xB3 xC3 2\" />")
					  _T("<gd name=\"yCxn3\" fmla=\"+/ yB3 yC3 2\" />")
					  _T("<gd name=\"xCxn4\" fmla=\"+/ xB4 xC4 2\" />")
					  _T("<gd name=\"yCxn4\" fmla=\"+/ yB4 yC4 2\" />")
					  _T("<gd name=\"xCxn5\" fmla=\"+/ r 0 xCxn4\" />")
					  _T("<gd name=\"xCxn6\" fmla=\"+/ r 0 xCxn3\" />")
					  _T("<gd name=\"xCxn7\" fmla=\"+/ r 0 xCxn2\" />")
					  _T("<gd name=\"xCxn8\" fmla=\"+/ r 0 xCxn1\" />")
					_T("</gdLst>")
					_T("<ahLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<ahXY gdRefY=\"adj1\" minY=\"0\" maxY=\"20000\">")
						_T("<pos x=\"xD9\" y=\"yD9\" />")
					  _T("</ahXY>")
					  _T("<ahXY gdRefX=\"adj2\" minX=\"0\" maxX=\"2679\">")
						_T("<pos x=\"xA9\" y=\"yD9\" />")
					  _T("</ahXY>")
					_T("</ahLst>")
					_T("<cxnLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<cxn ang=\"18600000\">")
						_T("<pos x=\"xCxn1\" y=\"yCxn1\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"21000000\">")
						_T("<pos x=\"xCxn2\" y=\"yCxn2\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"1800000\">")
						_T("<pos x=\"xCxn3\" y=\"yCxn3\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"4200000\">")
						_T("<pos x=\"xCxn4\" y=\"yCxn4\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"6600000\">")
						_T("<pos x=\"xCxn5\" y=\"yCxn4\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"9000000\">")
						_T("<pos x=\"xCxn6\" y=\"yCxn3\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"11400000\">")
						_T("<pos x=\"xCxn7\" y=\"yCxn2\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"13800000\">")
						_T("<pos x=\"xCxn8\" y=\"yCxn1\" />")
					  _T("</cxn>")
					  _T("<cxn ang=\"3cd4\">")
						_T("<pos x=\"hc\" y=\"yC9\" />")
					  _T("</cxn>")
					_T("</cxnLst>")
					_T("<rect l=\"xA8\" t=\"yD1\" r=\"xD1\" b=\"yD3\" xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\" />")
					_T("<pathLst xmlns=\"http://schemas.openxmlformats.org/drawingml/2006/main\">")
					  _T("<path>")
						_T("<moveTo>")
						  _T("<pt x=\"xA1\" y=\"yA1\" />")
						_T("</moveTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xB1\" y=\"yB1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC1\" y=\"yC1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD1\" y=\"yD1\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD1\" swAng=\"swAng1\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB2\" y=\"yB2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC2\" y=\"yC2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD2\" y=\"yD2\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD2\" swAng=\"swAng2\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB3\" y=\"yB3\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC3\" y=\"yC3\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD3\" y=\"yD3\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD3\" swAng=\"swAng3\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB4\" y=\"yB4\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC4\" y=\"yC4\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD4\" y=\"yD4\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD4\" swAng=\"swAng4\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB5\" y=\"yC4\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC5\" y=\"yB4\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD5\" y=\"yA4\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD5\" swAng=\"swAng3\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB6\" y=\"yC3\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC6\" y=\"yB3\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD6\" y=\"yA3\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD6\" swAng=\"swAng2\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB7\" y=\"yC2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC7\" y=\"yB2\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD7\" y=\"yA2\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD7\" swAng=\"swAng1\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xB8\" y=\"yC1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xC8\" y=\"yB1\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD8\" y=\"yA1\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD8\" swAng=\"swAng5\" />")
						_T("<lnTo>")
						  _T("<pt x=\"xE9\" y=\"yC9\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xF9\" y=\"yC9\" />")
						_T("</lnTo>")
						_T("<lnTo>")
						  _T("<pt x=\"xD9\" y=\"yD9\" />")
						_T("</lnTo>")
						_T("<arcTo hR=\"rh\" wR=\"rw\" stAng=\"bD9\" swAng=\"swAng5\" />")
						_T("<close />")
					  _T("</path>")
					_T("</pathLst>")
					_T("</ooxml-shape>")
				);
			}
	};
}