#pragma once

#ifndef DOCX_RENDERER_RESOURCES
#define DOCX_RENDERER_RESOURCES

const char* g_resource_app = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><Properties xmlns=\"http://schemas.openxmlformats.org/officeDocument/2006/extended-properties\"><Template>Normal.dotm</Template><TotalTime>1</TotalTime><Pages>1</Pages><Words>0</Words><Characters>0</Characters><Application>Microsoft Office Word</Application><DocSecurity>0</DocSecurity><Lines>1</Lines><Paragraphs>1</Paragraphs><ScaleCrop>false</ScaleCrop><LinksUpToDate>false</LinksUpToDate><CharactersWithSpaces>0</CharactersWithSpaces><SharedDoc>false</SharedDoc><HyperlinksChanged>false</HyperlinksChanged><AppVersion>12.0000</AppVersion></Properties>";
const char* g_resource_contenttypes = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><Types xmlns=\"http://schemas.openxmlformats.org/package/2006/content-types\"><Default Extension=\"rels\" ContentType=\"application/vnd.openxmlformats-package.relationships+xml\"/><Default Extension=\"xml\" ContentType=\"application/xml\"/><Default Extension=\"png\" ContentType=\"image/png\"/><Default Extension=\"jpg\" ContentType=\"image/jpg\"/><Override PartName=\"/word/document.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml\"/><Override PartName=\"/word/styles.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.wordprocessingml.styles+xml\"/><Override PartName=\"/word/settings.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.wordprocessingml.settings+xml\"/><Override PartName=\"/word/webSettings.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.wordprocessingml.webSettings+xml\"/><Override PartName=\"/word/fontTable.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.wordprocessingml.fontTable+xml\"/><Override PartName=\"/word/theme/theme.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.theme+xml\"/><Override PartName=\"/docProps/core.xml\" ContentType=\"application/vnd.openxmlformats-package.core-properties+xml\"/><Override PartName=\"/docProps/app.xml\" ContentType=\"application/vnd.openxmlformats-officedocument.extended-properties+xml\"/></Types>";
const char* g_resource_core = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><cp:coreProperties xmlns:cp=\"http://schemas.openxmlformats.org/package/2006/metadata/core-properties\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\"><dc:title/><dc:subject/><dc:creator/><cp:keywords/><dc:description/><cp:lastModifiedBy/><cp:revision>1</cp:revision></cp:coreProperties>";
const char* g_resource_rels = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><Relationships xmlns=\"http://schemas.openxmlformats.org/package/2006/relationships\"><Relationship Id=\"rId1\" Type=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument\" Target=\"word/document.xml\"/><Relationship Id=\"rId2\" Type=\"http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties\" Target=\"docProps/core.xml\"/><Relationship Id=\"rId3\" Type=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties\" Target=\"docProps/app.xml\"/></Relationships>";
const char* g_resource_settings = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><w:settings xmlns:w=\"http://schemas.openxmlformats.org/wordprocessingml/2006/main\" xmlns:m=\"http://schemas.openxmlformats.org/officeDocument/2006/math\" xmlns:o=\"urn:schemas-microsoft-com:office:office\" xmlns:v=\"urn:schemas-microsoft-com:vml\"><w:zoom w:percent=\"100\"/><w:defaultTabStop w:val=\"708\"/><w:drawingGridHorizontalSpacing/><w:displayHorizontalDrawingGridEvery/><w:characterSpacingControl w:val=\"doNotCompress\"/><w:compat/><m:mathPr><m:mathFont m:val=\"Cambria Math\"/><m:brkBin m:val=\"before\"/><m:brkBinSub m:val=\"--\"/><m:smallFrac m:val=\"off\"/><m:dispDef/><m:lMargin m:val=\"0\"/><m:rMargin m:val=\"0\"/><m:defJc m:val=\"centerGroup\"/><m:wrapIndent m:val=\"1440\"/><m:intLim m:val=\"subSup\"/><m:naryLim m:val=\"undOvr\"/></m:mathPr><w:themeFontLang w:val=\"ru-RU\"/><w:clrSchemeMapping w:bg1=\"light1\" w:t1=\"dark1\" w:bg2=\"light2\" w:t2=\"dark2\" w:accent1=\"accent1\" w:accent2=\"accent2\" w:accent3=\"accent3\" w:accent4=\"accent4\" w:accent5=\"accent5\" w:accent6=\"accent6\" w:hyperlink=\"hyperlink\" w:followedHyperlink=\"followedHyperlink\"/><w:shapeDefaults><o:shapedefaults v:ext=\"edit\" spidmax=\"3074\"/><o:shapelayout v:ext=\"edit\"><o:idmap v:ext=\"edit\" data=\"1\"/><o:rules v:ext=\"\"/></o:shapelayout></w:shapeDefaults><w:decimalSymbol w:val=\",\"/><w:listSeparator w:val=\";\"/></w:settings>";
const char* g_resource_styles = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><w:styles xmlns:w=\"http://schemas.openxmlformats.org/wordprocessingml/2006/main\"><w:docDefaults><w:rPrDefault><w:rPr><w:webHidden w:val=\"false\"/><w:lang w:val=\"ru-RU\" w:eastAsia=\"en-US\" w:bidi=\"ar-SA\"/><w:rFonts w:eastAsiaTheme=\"minorHAnsi\" w:ascii=\"Times New Roman\" w:hAnsi=\"Times New Roman\" w:cs=\"Times New Roman\"/></w:rPr></w:rPrDefault><w:pPrDefault><w:pPr/></w:pPrDefault></w:docDefaults><w:latentStyles w:defLockedState=\"false\" w:defUIPriority=\"99\" w:defSemiHidden=\"true\" w:defUnhideWhenUsed=\"true\" w:defQFormat=\"false\" w:count=\"267\"><w:lsdException w:name=\"Normal\" w:semiHidden=\"false\" w:uiPriority=\"0\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"heading 1\" w:semiHidden=\"false\" w:uiPriority=\"9\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 2\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 3\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 4\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 5\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 6\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 7\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 8\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"heading 9\" w:uiPriority=\"9\" w:qFormat=\"true\"/><w:lsdException w:name=\"toc 1\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 2\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 3\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 4\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 5\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 6\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 7\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 8\" w:uiPriority=\"39\"/><w:lsdException w:name=\"toc 9\" w:uiPriority=\"39\"/><w:lsdException w:name=\"caption\" w:uiPriority=\"35\" w:qFormat=\"true\"/><w:lsdException w:name=\"Title\" w:semiHidden=\"false\" w:uiPriority=\"10\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Default Paragraph Font\" w:uiPriority=\"1\"/><w:lsdException w:name=\"Subtitle\" w:semiHidden=\"false\" w:uiPriority=\"11\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Strong\" w:semiHidden=\"false\" w:uiPriority=\"22\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Emphasis\" w:semiHidden=\"false\" w:uiPriority=\"20\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Table Grid\" w:semiHidden=\"false\" w:uiPriority=\"59\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Placeholder Text\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"No Spacing\" w:semiHidden=\"false\" w:uiPriority=\"1\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Light Shading\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Revision\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"List Paragraph\" w:semiHidden=\"false\" w:uiPriority=\"34\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Quote\" w:semiHidden=\"false\" w:uiPriority=\"29\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Intense Quote\" w:semiHidden=\"false\" w:uiPriority=\"30\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Medium List 2 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 1\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 2\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 3\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 4\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 5\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Shading Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"60\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light List Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"61\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Light Grid Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"62\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 1 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"63\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Shading 2 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"64\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 1 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"65\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium List 2 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"66\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 1 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"67\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 2 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"68\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Medium Grid 3 Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"69\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Dark List Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"70\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Shading Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"71\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful List Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"72\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Colorful Grid Accent 6\" w:semiHidden=\"false\" w:uiPriority=\"73\" w:unhideWhenUsed=\"false\"/><w:lsdException w:name=\"Subtle Emphasis\" w:semiHidden=\"false\" w:uiPriority=\"19\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Intense Emphasis\" w:semiHidden=\"false\" w:uiPriority=\"21\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Subtle Reference\" w:semiHidden=\"false\" w:uiPriority=\"31\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Intense Reference\" w:semiHidden=\"false\" w:uiPriority=\"32\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Book Title\" w:semiHidden=\"false\" w:uiPriority=\"33\" w:unhideWhenUsed=\"false\" w:qFormat=\"true\"/><w:lsdException w:name=\"Bibliography\" w:uiPriority=\"37\"/><w:lsdException w:name=\"TOC Heading\" w:uiPriority=\"39\" w:qFormat=\"true\"/></w:latentStyles><w:style w:type=\"paragraph\" w:default=\"1\" w:styleId=\"Normal\"><w:name w:val=\"Normal\"/></w:style><w:style w:type=\"character\" w:default=\"1\" w:styleId=\"DefaultParagraphFont\"><w:name w:val=\"Default Paragraph Font\"/><w:semiHidden/><w:unhideWhenUsed/><w:uiPriority w:val=\"1\"/></w:style><w:style w:type=\"table\" w:default=\"1\" w:styleId=\"TableNormal\"><w:name w:val=\"Normal Table\"/><w:semiHidden/><w:unhideWhenUsed/><w:qFormat/><w:uiPriority w:val=\"99\"/><w:tblPr><w:tblInd w:w=\"0\" w:type=\"dxa\"/><w:tblCellMar><w:top w:w=\"0\" w:type=\"dxa\"/><w:left w:w=\"108\" w:type=\"dxa\"/><w:bottom w:w=\"0\" w:type=\"dxa\"/><w:right w:w=\"108\" w:type=\"dxa\"/></w:tblCellMar></w:tblPr></w:style><w:style w:type=\"numbering\" w:default=\"1\" w:styleId=\"NoList\"><w:name w:val=\"No List\"/><w:semiHidden/><w:unhideWhenUsed/><w:uiPriority w:val=\"99\"/></w:style></w:styles>";
const char* g_resource_theme = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><a:theme xmlns:a=\"http://schemas.openxmlformats.org/drawingml/2006/main\" name=\"Office Theme\"><a:themeElements><a:clrScheme name=\"Office\"><a:dk1><a:sysClr val=\"windowText\" lastClr=\"000000\"/></a:dk1><a:lt1><a:sysClr val=\"window\" lastClr=\"FFFFFF\"/></a:lt1><a:dk2><a:srgbClr val=\"1F497D\"/></a:dk2><a:lt2><a:srgbClr val=\"EEECE1\"/></a:lt2><a:accent1><a:srgbClr val=\"4F81BD\"/></a:accent1><a:accent2><a:srgbClr val=\"C0504D\"/></a:accent2><a:accent3><a:srgbClr val=\"9BBB59\"/></a:accent3><a:accent4><a:srgbClr val=\"8064A2\"/></a:accent4><a:accent5><a:srgbClr val=\"4BACC6\"/></a:accent5><a:accent6><a:srgbClr val=\"F79646\"/></a:accent6><a:hlink><a:srgbClr val=\"0000FF\"/></a:hlink><a:folHlink><a:srgbClr val=\"800080\"/></a:folHlink></a:clrScheme><a:fontScheme name=\"Office\"><a:majorFont><a:latin typeface=\"Cambria\"/><a:ea typeface=\"\"/><a:cs typeface=\"\"/><a:font script=\"Jpan\" typeface=\"ＭＳ ゴシック\"/><a:font script=\"Hang\" typeface=\"맑은 고딕\"/><a:font script=\"Hans\" typeface=\"宋体\"/><a:font script=\"Hant\" typeface=\"新細明體\"/><a:font script=\"Arab\" typeface=\"Times New Roman\"/><a:font script=\"Hebr\" typeface=\"Times New Roman\"/><a:font script=\"Thai\" typeface=\"Angsana New\"/><a:font script=\"Ethi\" typeface=\"Nyala\"/><a:font script=\"Beng\" typeface=\"Vrinda\"/><a:font script=\"Gujr\" typeface=\"Shruti\"/><a:font script=\"Khmr\" typeface=\"MoolBoran\"/><a:font script=\"Knda\" typeface=\"Tunga\"/><a:font script=\"Guru\" typeface=\"Raavi\"/><a:font script=\"Cans\" typeface=\"Euphemia\"/><a:font script=\"Cher\" typeface=\"Plantagenet Cherokee\"/><a:font script=\"Yiii\" typeface=\"Microsoft Yi Baiti\"/><a:font script=\"Tibt\" typeface=\"Microsoft Himalaya\"/><a:font script=\"Thaa\" typeface=\"MV Boli\"/><a:font script=\"Deva\" typeface=\"Mangal\"/><a:font script=\"Telu\" typeface=\"Gautami\"/><a:font script=\"Taml\" typeface=\"Latha\"/><a:font script=\"Syrc\" typeface=\"Estrangelo Edessa\"/><a:font script=\"Orya\" typeface=\"Kalinga\"/><a:font script=\"Mlym\" typeface=\"Kartika\"/><a:font script=\"Laoo\" typeface=\"DokChampa\"/><a:font script=\"Sinh\" typeface=\"Iskoola Pota\"/><a:font script=\"Mong\" typeface=\"Mongolian Baiti\"/><a:font script=\"Viet\" typeface=\"Times New Roman\"/><a:font script=\"Uigh\" typeface=\"Microsoft Uighur\"/></a:majorFont><a:minorFont><a:latin typeface=\"Calibri\"/><a:ea typeface=\"\"/><a:cs typeface=\"\"/><a:font script=\"Jpan\" typeface=\"ＭＳ 明朝\"/><a:font script=\"Hang\" typeface=\"맑은 고딕\"/><a:font script=\"Hans\" typeface=\"宋体\"/><a:font script=\"Hant\" typeface=\"新細明體\"/><a:font script=\"Arab\" typeface=\"Arial\"/><a:font script=\"Hebr\" typeface=\"Arial\"/><a:font script=\"Thai\" typeface=\"Cordia New\"/><a:font script=\"Ethi\" typeface=\"Nyala\"/><a:font script=\"Beng\" typeface=\"Vrinda\"/><a:font script=\"Gujr\" typeface=\"Shruti\"/><a:font script=\"Khmr\" typeface=\"DaunPenh\"/><a:font script=\"Knda\" typeface=\"Tunga\"/><a:font script=\"Guru\" typeface=\"Raavi\"/><a:font script=\"Cans\" typeface=\"Euphemia\"/><a:font script=\"Cher\" typeface=\"Plantagenet Cherokee\"/><a:font script=\"Yiii\" typeface=\"Microsoft Yi Baiti\"/><a:font script=\"Tibt\" typeface=\"Microsoft Himalaya\"/><a:font script=\"Thaa\" typeface=\"MV Boli\"/><a:font script=\"Deva\" typeface=\"Mangal\"/><a:font script=\"Telu\" typeface=\"Gautami\"/><a:font script=\"Taml\" typeface=\"Latha\"/><a:font script=\"Syrc\" typeface=\"Estrangelo Edessa\"/><a:font script=\"Orya\" typeface=\"Kalinga\"/><a:font script=\"Mlym\" typeface=\"Kartika\"/><a:font script=\"Laoo\" typeface=\"DokChampa\"/><a:font script=\"Sinh\" typeface=\"Iskoola Pota\"/><a:font script=\"Mong\" typeface=\"Mongolian Baiti\"/><a:font script=\"Viet\" typeface=\"Arial\"/><a:font script=\"Uigh\" typeface=\"Microsoft Uighur\"/></a:minorFont></a:fontScheme><a:fmtScheme name=\"Office\"><a:fillStyleLst><a:solidFill><a:schemeClr val=\"phClr\"/></a:solidFill><a:gradFill rotWithShape=\"1\"><a:gsLst><a:gs pos=\"0\"><a:schemeClr val=\"phClr\"><a:tint val=\"50000\"/><a:satMod val=\"300000\"/></a:schemeClr></a:gs><a:gs pos=\"35000\"><a:schemeClr val=\"phClr\"><a:tint val=\"37000\"/><a:satMod val=\"300000\"/></a:schemeClr></a:gs><a:gs pos=\"100000\"><a:schemeClr val=\"phClr\"><a:tint val=\"15000\"/><a:satMod val=\"350000\"/></a:schemeClr></a:gs></a:gsLst><a:lin ang=\"16200000\" scaled=\"1\"/></a:gradFill><a:gradFill rotWithShape=\"1\"><a:gsLst><a:gs pos=\"0\"><a:schemeClr val=\"phClr\"><a:shade val=\"51000\"/><a:satMod val=\"130000\"/></a:schemeClr></a:gs><a:gs pos=\"80000\"><a:schemeClr val=\"phClr\"><a:shade val=\"93000\"/><a:satMod val=\"130000\"/></a:schemeClr></a:gs><a:gs pos=\"100000\"><a:schemeClr val=\"phClr\"><a:shade val=\"94000\"/><a:satMod val=\"135000\"/></a:schemeClr></a:gs></a:gsLst><a:lin ang=\"16200000\" scaled=\"0\"/></a:gradFill></a:fillStyleLst><a:lnStyleLst><a:ln w=\"9525\" cap=\"flat\" cmpd=\"sng\" algn=\"ctr\"><a:solidFill><a:schemeClr val=\"phClr\"><a:shade val=\"95000\"/><a:satMod val=\"105000\"/></a:schemeClr></a:solidFill><a:prstDash val=\"solid\"/></a:ln><a:ln w=\"25400\" cap=\"flat\" cmpd=\"sng\" algn=\"ctr\"><a:solidFill><a:schemeClr val=\"phClr\"/></a:solidFill><a:prstDash val=\"solid\"/></a:ln><a:ln w=\"38100\" cap=\"flat\" cmpd=\"sng\" algn=\"ctr\"><a:solidFill><a:schemeClr val=\"phClr\"/></a:solidFill><a:prstDash val=\"solid\"/></a:ln></a:lnStyleLst><a:effectStyleLst><a:effectStyle><a:effectLst><a:outerShdw blurRad=\"40000\" dist=\"20000\" dir=\"5400000\" rotWithShape=\"0\"><a:srgbClr val=\"000000\"><a:alpha val=\"38000\"/></a:srgbClr></a:outerShdw></a:effectLst></a:effectStyle><a:effectStyle><a:effectLst><a:outerShdw blurRad=\"40000\" dist=\"23000\" dir=\"5400000\" rotWithShape=\"0\"><a:srgbClr val=\"000000\"><a:alpha val=\"35000\"/></a:srgbClr></a:outerShdw></a:effectLst></a:effectStyle><a:effectStyle><a:effectLst><a:outerShdw blurRad=\"40000\" dist=\"23000\" dir=\"5400000\" rotWithShape=\"0\"><a:srgbClr val=\"000000\"><a:alpha val=\"35000\"/></a:srgbClr></a:outerShdw></a:effectLst><a:scene3d><a:camera  prst=\"orthographicFront\"><a:rot lat=\"0\" lon=\"0\" rev=\"0\"/></a:camera ><a:lightRig rig=\"threePt\" dir=\"t\"><a:rot lat=\"0\" lon=\"0\" rev=\"1200000\"/></a:lightRig></a:scene3d><a:sp3d><a:bevelT w=\"63500\" h=\"25400\"/></a:sp3d></a:effectStyle></a:effectStyleLst><a:bgFillStyleLst><a:solidFill><a:schemeClr val=\"phClr\"/></a:solidFill><a:gradFill rotWithShape=\"1\"><a:gsLst><a:gs pos=\"0\"><a:schemeClr val=\"phClr\"><a:tint val=\"40000\"/><a:satMod val=\"350000\"/></a:schemeClr></a:gs><a:gs pos=\"40000\"><a:schemeClr val=\"phClr\"><a:tint val=\"45000\"/><a:shade val=\"99000\"/><a:satMod val=\"350000\"/></a:schemeClr></a:gs><a:gs pos=\"100000\"><a:schemeClr val=\"phClr\"><a:shade val=\"20000\"/><a:satMod val=\"255000\"/></a:schemeClr></a:gs></a:gsLst><a:path path=\"circle\"><a:fillToRect l=\"50000\" t=\"-80000\" r=\"50000\" b=\"180000\"/></a:path></a:gradFill><a:gradFill rotWithShape=\"1\"><a:gsLst><a:gs pos=\"0\"><a:schemeClr val=\"phClr\"><a:tint val=\"80000\"/><a:satMod val=\"300000\"/></a:schemeClr></a:gs><a:gs pos=\"100000\"><a:schemeClr val=\"phClr\"><a:shade val=\"30000\"/><a:satMod val=\"200000\"/></a:schemeClr></a:gs></a:gsLst><a:path path=\"circle\"><a:fillToRect l=\"50000\" t=\"50000\" r=\"50000\" b=\"50000\"/></a:path></a:gradFill></a:bgFillStyleLst></a:fmtScheme></a:themeElements><a:objectDefaults/><a:extraClrSchemeLst/></a:theme>";
const char* g_resource_websettings = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?><w:webSettings xmlns:w=\"http://schemas.openxmlformats.org/wordprocessingml/2006/main\"><w:optimizeForBrowser/></w:webSettings>";

#endif
