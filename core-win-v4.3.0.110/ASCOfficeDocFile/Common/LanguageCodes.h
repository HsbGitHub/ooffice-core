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

namespace DocFileFormat
{
  enum LanguageCode
  {
    Nothing = 1024,
    Afrikaans = 1078,
    Albanian = 1052,
    Amharic = 1118,
    ArabicAlgeria = 5121,
    ArabicBahrain = 15361,
    ArabicEgypt = 3073,
    ArabicIraq = 2049,
    ArabicJordan = 11265,
    ArabicKuwait = 13313,
    ArabicLebanon = 12289,
    ArabicLibya = 4097,
    ArabicMorocco = 6145,
    ArabicOman = 8193,
    ArabicQatar = 16385,
    ArabicSaudiArabia = 1025,
    ArabicSyria = 10241,
    ArabicTunisia = 7169,
    ArabicUAE = 14337,
    ArabicYemen = 9217,
    Armenian = 1067,
    Assamese = 1101,
    AzeriCyrillic = 2092,
    AzeriLatin = 1068,
    Basque = 1069,
    Belarusian = 1059,
    Bengali = 1093,
    BengaliBangladesh = 2117,
    Bulgarian = 1026,
    Burmese = 1109,
    Catalan = 1027,
    Cherokee = 1116,
    ChineseHongKong = 3076,
    ChineseMacao = 5124,
    ChinesePRC = 2052,
    ChineseSingapore = 4100,
    ChineseTaiwan = 1028,
    Croatian = 1050,
    Czech = 1029,
    Danish = 1030,
    Divehi = 1125,
    DutchBelgium = 2067,
    DutchNetherlands = 1043,
    Edo = 1126,
    EnglishAustralia = 3081,
    EnglishBelize = 10249,
    EnglishCanada = 4105,
    EnglishCaribbean = 9225,
    EnglishHongKong = 15369,
    EnglishIndia = 16393,
    EnglishIndonesia = 14345,
    EnglishIreland = 6153,
    EnglishJamaica = 8201,
    EnglishMalaysia = 17417,
    EnglishNewZealand = 5129,
    EnglishPhilippines = 13321,
    EnglishSingapore = 18441,
    EnglishSouthAfrica = 7177,
    EnglishTrinidadAndTobago = 11273,
    EnglishUK = 2057,
    EnglishUS = 1033,
    EnglishZimbabwe = 12297,
    Estonian = 1061,
    Faeroese = 1080,
    Farsi = 1065,
    Filipino = 1124,
    Finnish = 1035,
    FrenchBelgium = 2060,
    FrenchCameroon = 11276,
    FrenchCanada = 3084,
    FrenchCongoDRC = 9228,
    FrenchCotedIvoire = 12300,
    FrenchFrance = 1036,
    FrenchHaiti = 15372,
    FrenchLuxembourg = 5132,
    FrenchMali = 13324,
    FrenchMonaco = 6156,
    FrenchMorocco = 14348,
    FrenchReunion = 8204,
    FrenchSenegal = 10252,
    FrenchSwitzerland = 4108,
    FrenchWestIndies = 7180,
    FrisianNetherlands = 1122,
    Fulfulde = 1127,
    FYROMacedonian = 1071,
    GaelicIreland = 2108,
    GaelicScotland = 1084,
    Galician = 1110,
    Georgian = 1079,
    GermanAustria = 3079,
    GermanGermany = 1031,
    GermanLiechtenstein = 5127,
    GermanLuxembourg = 4103,
    GermanSwitzerland = 2055,
    Greek = 1032,
    Guarani = 1140,
    Gujarati = 1095,
    Hausa = 1128,
    Hawaiian = 1141,
    Hebrew = 1037,
    Hindi = 1081,
    Hungarian = 1038,
    Ibibio = 1129,
    Icelandic = 1039,
    Igbo = 1136,
    Indonesian = 1057,
    Inuktitut = 1117,
    ItalianItaly = 1040,
    ItalianSwitzerland = 2064,
    Japanese = 1041,
    Kannada = 1099,
    Kanuri = 1137,
    Kashmiri = 2144,
    KashmiriArabic = 1120,
    Kazakh = 1087,
    Khmer = 1107,
    Konkani = 1111,
    Korean = 1042,
    Kyrgyz = 1088,
    Lao = 1108,
    Latin = 1142,
    Latvian = 1062,
    Lithuanian = 1063,
    Malay = 1086,
    MalayBruneiDarussalam = 2110,
    Malayalam = 1100,
    Maltese = 1082,
    Manipuri = 1112,
    Maori = 1153,
    Marathi = 1102,
    Mongolian = 1104,
    MongolianMongolian = 2128,
    Nepali = 1121,
    NepaliIndia = 2145,
    NorwegianBokmal = 1044,
    NorwegianNynorsk = 2068,
    Oriya = 1096,
    Oromo = 1138,
    Papiamentu = 1145,
    Pashto = 1123,
    Polish = 1045,
    PortugueseBrazil = 1046,
    PortuguesePortugal = 2070,
    Punjabi = 1094,
    PunjabiPakistan = 2118,
    QuechuaBolivia = 1131,
    QuechuaEcuador = 2155,
    QuechuaPeru = 3179,
    RhaetoRomanic = 1047,
    RomanianMoldova = 2072,
    RomanianRomania = 1048,
    RussianMoldova = 2073,
    RussianRussia = 1049,
    SamiLappish = 1083,
    Sanskrit = 1103,
    Sepedi = 1132,
    SerbianCyrillic = 3098,
    SerbianLatin = 2074,
    SindhiArabic = 2137,
    SindhiDevanagari = 1113,
    Sinhalese = 1115,
    Slovak = 1051,
    Slovenian = 1060,
    Somali = 1143,
    Sorbian = 1070,
    SpanishArgentina = 11274,
    SpanishBolivia = 16394,
    SpanishChile = 13322,
    SpanishColombia = 9226,
    SpanishCostaRica = 5130,
    SpanishDominicanRepublic = 7178,
    SpanishEcuador = 12298,
    SpanishElSalvador = 17418,
    SpanishGuatemala = 4106,
    SpanishHonduras = 18442,
    SpanishMexico = 2058,
    SpanishNicaragua = 19466,
    SpanishPanama = 6154,
    SpanishParaguay = 15370,
    SpanishPeru = 10250,
    SpanishPuertoRico = 20490,
    SpanishSpainModernSort = 3082,
    SpanishSpainTraditionalSort = 1034,
    SpanishUruguay = 14346,
    SpanishVenezuela = 8202,
    Sutu = 1072,
    Swahili = 1089,
    SwedishFinland = 2077,
    SwedishSweden = 1053,
    Syriac = 1114,
    Tajik = 1064,
    Tamazight = 1119,
    TamazightLatin = 2143,
    Tamil = 1097,
    Tatar = 1092,
    Telugu = 1098,
    Thai = 1054,
    TibetanBhutan = 2129,
    TibetanPRC = 1105,
    TigrignaEritrea = 2163,
    TigrignaEthiopia = 1139,
    Tsonga = 1073,
    Tswana = 1074,
    Turkish = 1055,
    Turkmen = 1090,
    Ukrainian = 1058,
    Urdu = 1056,
    UzbekCyrillic = 2115,
    UzbekLatin = 1091,
    Venda = 1075,
    Vietnamese = 1066,
    Welsh = 1106,
    Xhosa = 1076,
    Yi = 1144,
    Yiddish = 1085,
    Yoruba = 1130,
    Zulu = 1077
  };
}