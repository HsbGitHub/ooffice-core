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

#ifdef MAKE_HRESULT
#define AVS_ERROR_FIRST					MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0300)
#else
#define AVS_ERROR_FIRST                 (((unsigned long)(1)<<31) | ((unsigned long)(4)<<16) | ((unsigned long)(0x0300)))
#endif

#define AVS_ERROR_UNEXPECTED				(AVS_ERROR_FIRST + 0x0000)
#define AVS_ERROR_BUSY						(AVS_ERROR_FIRST + 0x0001)
#define AVS_ERROR_MEMORY					(AVS_ERROR_FIRST + 0x0002)
#define AVS_ERROR_FILEACCESS				(AVS_ERROR_FIRST + 0x0003)
#define AVS_ERROR_FILEFORMAT				(AVS_ERROR_FIRST + 0x0004)
#define AVS_ERROR_PASSWORD					(AVS_ERROR_FIRST + 0x0005)
#define AVS_ERROR_DRM						(AVS_ERROR_FIRST + 0x0006)

// AVSOfficeUniversalConverter 0x0050 - 0x0075
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST						(AVS_ERROR_FIRST + 0x0050) 
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_XML_FORMAT					(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0001) //Входная XML имеет неправильный формат
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_CREATE_TEMP_DIR			(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0002) //Ошибка при создании темповой директории
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_REMOVE_TEMP_DIR			(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0003) //Ошибка при удалении темповой директории
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_CONVERT_THIS_FORMATS		(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0004) //Не поддерживается конвертация данных типов файлов
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_LOAD_FILE					(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0004) //Не поддерживается конвертация данных типов файлов
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_SAVE_FILE					(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0004) //Не поддерживается конвертация данных типов файлов
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_ADVERTISE					(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0005) //при добавлении рекламы
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_COPY						(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0006) //ошибка при копировании source в destination( копируются когда их тип совпадает )
#define AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_CREATE_EXTR_DIR			(AVS_UNIVERSALDOCUMENTCONVERTER_ERROR_FIRST + 0x0007) //ошибка при копировании source в destination( копируются когда их тип совпадает )


// AVSOfficeFile 0x0075 - 0x00100
#define AVS_OFFICEFILE_ERROR_FIRST										(AVS_ERROR_FIRST + 0x0075) 
#define AVS_OFFICEFILE_ERROR_CREATE_TEMP								(AVS_OFFICEFILE_ERROR_FIRST + 0x0001) //Ошибка при создании темповой директории или файла
#define AVS_OFFICEFILE_ERROR_UNSUPPORTED_LOAD_FORMAT					(AVS_OFFICEFILE_ERROR_FIRST + 0x0002) //Формат файла не поддерживается
#define AVS_OFFICEFILE_ERROR_UNSUPPORTED_SAVE_FORMAT					(AVS_OFFICEFILE_ERROR_FIRST + 0x0003) //Формат файла не поддерживается
#define AVS_OFFICEFILE_ERROR_SAVE_EMPTY									(AVS_OFFICEFILE_ERROR_FIRST + 0x0004) //Формат файла не поддерживается
#define AVS_OFFICEFILE_ERROR_PRINT_OUT_OF_AREA							(AVS_OFFICEFILE_ERROR_FIRST + 0x0005) //печать за границами области печати

//AVSOfficeMsFile
#define AVS_MSFILE_ERROR_OLDER			(AVS_ERROR_FIRST + 0x0090)


// AVSOdfFile	0x0100 - 0x0200
#define AVS_ODTFILE_ERROR_INPUT_FILE	(AVS_ERROR_FIRST + 0x0100)	// Ошибка в входном файле
#define AVS_ODTFILE_ERROR_ORIGIN_FILE	(AVS_ERROR_FIRST + 0x0101)	// Ошибка в шаблоном файле
#define AVS_ODTFILE_ERROR_CONVERT		(AVS_ERROR_FIRST + 0x0102)	// Ошибка при конвертации


// AVSTxtFile 0x0200 - 0x0300
#define AVS_TXTFILE_ERROR_INPUT_FILE	(AVS_ERROR_FIRST + 0x0200)	// Ошибка в входном файле
#define AVS_TXTFILE_ERROR_ORIGIN_FILE	(AVS_ERROR_FIRST + 0x0201)	// Ошибка в шаблоном файле
#define AVS_TXTFILE_ERROR_CONVERT		(AVS_ERROR_FIRST + 0x0202)	// Ошибка при конвертации

// AVSOfficePDFWriter 0x0300 - 0x0400

#define AVS_PDFWRITER_ERROR_FIRST 0x0300

#define AVS_OFFICEPDFWRITER_ERROR_ARRAY_COUNT_ERR                       (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0001)
#define AVS_OFFICEPDFWRITER_ERROR_ARRAY_ITEM_NOT_FOUND                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0002)
#define AVS_OFFICEPDFWRITER_ERROR_ARRAY_ITEM_UNEXPECTED_TYPE            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0003)
#define AVS_OFFICEPDFWRITER_ERROR_BINARY_LENGTH_ERR                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0004)
#define AVS_OFFICEPDFWRITER_ERROR_CANNOT_GET_PALLET                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0005)
#define AVS_OFFICEPDFWRITER_ERROR_DICT_COUNT_ERR                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0007)
#define AVS_OFFICEPDFWRITER_ERROR_DICT_ITEM_NOT_FOUND                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0008)
#define AVS_OFFICEPDFWRITER_ERROR_DICT_ITEM_UNEXPECTED_TYPE             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0009)
#define AVS_OFFICEPDFWRITER_ERROR_DICT_STREAM_LENGTH_NOT_FOUND          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000A)
#define AVS_OFFICEPDFWRITER_ERROR_DOC_ENCRYPTDICT_NOT_FOUND             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000B)
#define AVS_OFFICEPDFWRITER_ERROR_DOC_INVALID_OBJECT                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000C)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000D)
#define AVS_OFFICEPDFWRITER_ERROR_DUPLICATE_REGISTRATION                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000E)
#define AVS_OFFICEPDFWRITER_ERROR_EXCEED_JWW_CODE_NUM_LIMIT             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x000F)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0010)
#define AVS_OFFICEPDFWRITER_ERROR_ENCRYPT_INVALID_PASSWORD              (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0011)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0012)
#define AVS_OFFICEPDFWRITER_ERROR_ERR_UNKNOWN_CLASS                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0013)
#define AVS_OFFICEPDFWRITER_ERROR_EXCEED_GSTATE_LIMIT                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0014)
#define AVS_OFFICEPDFWRITER_ERROR_FAILD_TO_ALLOC_MEM                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0015)
#define AVS_OFFICEPDFWRITER_ERROR_FILE_IO_ERROR                         (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0016)
#define AVS_OFFICEPDFWRITER_ERROR_FILE_OPEN_ERROR                       (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0017)
#define AVS_OFFICEPDFWRITER_ERROR_FILE_WRITE_ERROR                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0018)
#define AVS_OFFICEPDFWRITER_ERROR_FONT_EXISTS                           (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0019)
#define AVS_OFFICEPDFWRITER_ERROR_FONT_INVALID_WIDTHS_TABLE             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001A)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_AFM_HEADER                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001B)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_ANNOTATION                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001C)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001D)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_BIT_PER_COMPONENT             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001E)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_CHAR_METRICS_DATA             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x001F)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_COLOR_SPACE                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0020)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_COMPRESSION_MODE              (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0021)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_DATE_TIME                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0022)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_DESTINATION                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0023)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0024)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_DOCUMENT                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0025)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_DOCUMENT_STATE                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0026)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_ENCODER                       (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0027)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_ENCODER_TYPE                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0028)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0029)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002A)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_ENCODING_NAME                 (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002B)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_ENCRYPT_KEY_LEN               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002C)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_FONTDEF_DATA                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002D)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_FONTDEF_TYPE                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002E)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_FONT_NAME                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x002F)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_IMAGE                         (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0030)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_JPEG_DATA                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0031)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_N_DATA                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0032)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_OBJECT                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0033)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_OBJ_ID                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0034)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_OPERATION                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0035)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_OUTLINE                       (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0036)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PAGE                          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0037)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PAGES                         (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0038)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PARAMETER                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0039)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003A)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PNG_IMAGE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003B)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_STREAM                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003C)
#define AVS_OFFICEPDFWRITER_ERROR_MISSING_FILE_NAME_ENTRY               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003D)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003E)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_TTC_FILE                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x003F)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_TTC_INDEX                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0040)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_WX_DATA                       (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0041)
#define AVS_OFFICEPDFWRITER_ERROR_ITEM_NOT_FOUND                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0042)
#define AVS_OFFICEPDFWRITER_ERROR_LIBPNG_ERROR                          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0043)
#define AVS_OFFICEPDFWRITER_ERROR_NAME_INVALID_VALUE                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0044)
#define AVS_OFFICEPDFWRITER_ERROR_NAME_OUT_OF_RANGE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0045)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0046)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0047)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_PARAM_COUNT              (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0048)
#define AVS_OFFICEPDFWRITER_ERROR_PAGES_MISSING_KIDS_ENTRY              (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0049)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_CANNOT_FIND_OBJECT               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004A)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_CANNOT_GET_ROOT_PAGES            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004B)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_CANNOT_RESTORE_GSTATE            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004C)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_CANNOT_SET_PARENT                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004D)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_FONT_NOT_FOUND                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004E)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_FONT                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x004F)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_FONT_SIZE                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0050)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_GMODE                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0051)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_INDEX                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0052)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_ROTATE_VALUE             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0053)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_SIZE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0054)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_XOBJECT                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0055)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_OUT_OF_RANGE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0056)
#define AVS_OFFICEPDFWRITER_ERROR_REAL_OUT_OF_RANGE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0057)
#define AVS_OFFICEPDFWRITER_ERROR_STREAM_EOF                            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0058)
#define AVS_OFFICEPDFWRITER_ERROR_STREAM_READLN_CONTINUE                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0059)
//                                                                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005A)
#define AVS_OFFICEPDFWRITER_ERROR_STRING_OUT_OF_RANGE                   (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005B)
#define AVS_OFFICEPDFWRITER_ERROR_THIS_FUNC_WAS_SKIPPED                 (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005C)
#define AVS_OFFICEPDFWRITER_ERROR_TTF_CANNOT_EMBEDDING_FONT             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005D)
#define AVS_OFFICEPDFWRITER_ERROR_TTF_INVALID_CMAP                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005E)
#define AVS_OFFICEPDFWRITER_ERROR_TTF_INVALID_FORMAT                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x005F)
#define AVS_OFFICEPDFWRITER_ERROR_TTF_MISSING_TABLE                     (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0060)
#define AVS_OFFICEPDFWRITER_ERROR_UNSUPPORTED_FONT_TYPE                 (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0061)
#define AVS_OFFICEPDFWRITER_ERROR_UNSUPPORTED_FUNC                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0062)
#define AVS_OFFICEPDFWRITER_ERROR_UNSUPPORTED_JPEG_FORMAT               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0063)
#define AVS_OFFICEPDFWRITER_ERROR_UNSUPPORTED_TYPE1_FONT                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0064)
#define AVS_OFFICEPDFWRITER_ERROR_XREF_COUNT_ERR                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0065)
#define AVS_OFFICEPDFWRITER_ERROR_ZLIB_ERROR                            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0066)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PAGE_INDEX                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0067)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_URL                           (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0068)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_LAYOUT_OUT_OF_RANGE              (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0069)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_MODE_OUT_OF_RANGE                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0070)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_NUM_STYLE_OUT_OF_RANGE           (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0071)
#define AVS_OFFICEPDFWRITER_ERROR_ANNOT_INVALID_ICON                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0072)
#define AVS_OFFICEPDFWRITER_ERROR_ANNOT_INVALID_BORDER_STYLE            (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0073)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_DIRECTION                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0074)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_FONT                          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0075)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INSUFFICIENT_SPACE               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0076)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_DISPLAY_TIME             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0077)
#define AVS_OFFICEPDFWRITER_ERROR_PAGE_INVALID_TRANSITION_TIME          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0078)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_PAGE_SLIDESHOW_TYPE           (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0079)
#define AVS_OFFICEPDFWRITER_ERROR_EXT_GSTATE_OUT_OF_RANGE               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0080)
#define AVS_OFFICEPDFWRITER_ERROR_INVALID_EXT_GSTATE                    (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0081)
#define AVS_OFFICEPDFWRITER_ERROR_EXT_GSTATE_READ_ONLY                  (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0082)
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_DESTINATION_NOT_FOUND         (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0083)
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_EXTGSTATE_NOT_FOUND           (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0084)        
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_FONT_NOT_FOUND                (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0085)             
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_ANNOTATION_NOT_FOUND          (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0086)       
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_OUTLINE_NOT_FOUND             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0087)          
#define AVS_OFFICEPDFWRITER_ERROR_CURRENT_IMAGE_NOT_FOUND               (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0088)            
#define AVS_OFFICEPDFWRITER_ERROR_FONT_NOT_FOUND                        (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x0089)            
#define AVS_OFFICEPDFWRITER_ERROR_DRAW_PATH                             (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x008A)            
#define AVS_OFFICEPDFWRITER_ERROR_BAD_SAFEARRAY                         (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x008B)            
#define AVS_OFFICEPDFWRITER_ERROR_AVS_REGISTRATION                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x008C)  
#define AVS_OFFICEPDFWRITER_ERROR_BAD_COMMAND_TYPE                      (AVS_ERROR_FIRST + AVS_PDFWRITER_ERROR_FIRST + 0x008D)

// AVSOfficePDFReader 0x0400 - 0x0500

#define AVS_PDFREADER_ERROR_FIRST 0x0400
 
#define AVS_OFFICEPDFREADER_ERROR_OPEN_PDF                              (AVS_ERROR_FIRST + AVS_PDFREADER_ERROR_FIRST + 0x0001)
#define AVS_OFFICEPDFREADER_ERROR_BAD_CATALOG                           (AVS_ERROR_FIRST + AVS_PDFREADER_ERROR_FIRST + 0x0002)
#define AVS_OFFICEPDFREADER_ERROR_DAMAGED_PDF                           (AVS_ERROR_FIRST + AVS_PDFREADER_ERROR_FIRST + 0x0003)
#define AVS_OFFICEPDFREADER_ERROR_ENCRYPTED_PDF                         (AVS_ERROR_FIRST + AVS_PDFREADER_ERROR_FIRST + 0x0004)
#define AVS_OFFICEPDFREADER_ERROR_NOT_ENOUGH_MEMORY                     (AVS_ERROR_FIRST + AVS_PDFREADER_ERROR_FIRST + 0x0005)

// AVSOfficePDFReader 0x1000 - 0x1300
#define AVS_FILEUTILS_ERROR_FIRST 0x1000
#define AVS_FILEUTILS_ERROR_UNKNOWN                                     (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0001)
#define AVS_FILEUTILS_ERROR_CONVERT                                     (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0050)
#define AVS_FILEUTILS_ERROR_CONVERT_DOWNLOAD                            (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0051)
#define AVS_FILEUTILS_ERROR_CONVERT_UNKNOWN_FORMAT                      (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0052)
#define AVS_FILEUTILS_ERROR_CONVERT_TIMEOUT                             (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0053)
#define AVS_FILEUTILS_ERROR_CONVERT_READ_FILE                           (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0054)
//#define AVS_FILEUTILS_ERROR_CONVERT_MS_OFFCRYPTO                        (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0055)
#define AVS_FILEUTILS_ERROR_CONVERT_CORRUPTED                           (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0056)
#define AVS_FILEUTILS_ERROR_CONVERT_LIBREOFFICE                         (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0057)
#define AVS_FILEUTILS_ERROR_CONVERT_PARAMS                              (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0058)
#define AVS_FILEUTILS_ERROR_CONVERT_NEED_PARAMS                         (AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x0059)
#define AVS_FILEUTILS_ERROR_CONVERT_DRM									(AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x005a)
#define AVS_FILEUTILS_ERROR_CONVERT_PASSWORD							(AVS_ERROR_FIRST + AVS_FILEUTILS_ERROR_FIRST + 0x005b)
