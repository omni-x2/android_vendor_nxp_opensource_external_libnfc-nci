 /*
  * Copyright (C) 2015 NXP Semiconductors
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  */
#ifdef __cplusplus

extern "C" {

#endif


#ifndef ALALIB_H_
#define ALALIB_H_

#include "IChannel.h"

/*******************************************************************************
**
** Function:        ALA_Init
**
** Description:     Initializes the ALA library and opens the DWP communication channel
**
** Returns:         SUCCESS if ok.
**
*******************************************************************************/
unsigned char ALA_Init(IChannel *channel);

/*******************************************************************************
**
** Function:        ALA_Start
**
** Description:     Starts the ALA over DWP
**
** Returns:         SUCCESS if ok.
**
*******************************************************************************/
#if(NXP_LDR_SVC_VER_2 == TRUE)
unsigned char ALA_Start(const char *name, const char *dest, uint8_t *pdata, uint16_t len, uint8_t *respSW);
#else
unsigned char ALA_Start(const char *name, uint8_t *pdata, uint16_t len);
#endif

/*******************************************************************************
**
** Function:        ALA_DeInit
**
** Description:     Deinitializes the ALA Lib
**
** Returns:         true if ok.
**
*******************************************************************************/
bool ALA_DeInit();

#if(NXP_LDR_SVC_VER_2 == TRUE)
/*******************************************************************************
**
** Function:        ALA_lsGetVersion
**
** Description:     Get the Loader service Applet and cleint version
**
** Returns:         byte[] array.
**
*******************************************************************************/
unsigned char ALA_lsGetVersion(uint8_t *pVersion);
unsigned char ALA_lsGetStatus(uint8_t *pVersion);
unsigned char ALA_lsGetAppletStatus(uint8_t *pVersion);
#else
void ALA_GetlistofApplets(char *list[], uint8_t* num);

unsigned char ALA_GetCertificateKey(uint8_t *pKey, int32_t *pKeylen);
#endif

inline int FSCANF_BYTE(FILE *stream, const char *format, void* pVal)
{
    int Result = 0;

    if((NULL != stream) && (NULL != format) && (NULL != pVal))
    {
        unsigned int dwVal;
        unsigned char* pTmp = (unsigned char*)pVal;
        Result = fscanf(stream, format, &dwVal);

        (*pTmp) = (unsigned char)(dwVal & 0x000000FF);
    }
    return Result;
}

#endif /* ALALIB_H_ */

#ifdef __cplusplus

}

#endif
