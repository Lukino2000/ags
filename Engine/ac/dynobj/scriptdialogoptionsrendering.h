//=============================================================================
//
// Adventure Game Studio (AGS)
//
// Copyright (C) 1999-2011 Chris Jones and 2011-20xx others
// The full list of copyright holders can be found in the Copyright.txt
// file, which is part of this source code distribution.
//
// The AGS source code is provided under the Artistic License 2.0.
// A copy of this license can be found in the file License.txt and at
// http://www.opensource.org/licenses/artistic-license-2.0.php
//
//=============================================================================

#ifndef __AC_SCRIPTDIALOGOPTIONSRENDERING_H
#define __AC_SCRIPTDIALOGOPTIONSRENDERING_H

#include "ac/dynobj/scriptdrawingsurface.h"

struct ScriptDialogOptionsRendering : AGSCCDynamicObject {
    int x, y, width, height;
    bool hasAlphaChannel;
    int parserTextboxX, parserTextboxY;
    int parserTextboxWidth;
    int dialogID;
    int activeOptionID;
    int chosenOptionID;
    ScriptDrawingSurface *surfaceToRenderTo;
    bool surfaceAccessed;
    bool needRepaint;

    // return the type name of the object
    virtual const char *GetType();

    // serialize the object into BUFFER (which is BUFSIZE bytes)
    // return number of bytes used
    virtual int Serialize(const char *address, char *buffer, int bufsize);

    virtual void Unserialize(int index, const char *serializedData, int dataSize);

    void Reset();

    ScriptDialogOptionsRendering();
};


#endif // __AC_SCRIPTDIALOGOPTIONSRENDERING_H