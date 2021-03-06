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

#ifndef __AC_GUISLIDER_H
#define __AC_GUISLIDER_H

#include <vector>
#include "gui/guiobject.h"

namespace AGS
{
namespace Common
{

class GUISlider : public GUIObject
{
public:
    GUISlider();

    // Tells if the slider is horizontal (otherwise - vertical)
    bool         IsHorizontal() const;
    virtual bool IsOverControl(int x, int y, int leeway) const override;

    // Operations
    virtual void Draw(Bitmap *ds) override;

    // Events
    virtual bool OnMouseDown() override;
    virtual void OnMouseMove(int xp, int yp) override;
    virtual void OnMouseUp() override;

    // Serialization
    virtual void WriteToFile(Stream *out) override;
    virtual void ReadFromFile(Stream *in, GuiVersion gui_version) override;
    virtual void ReadFromSavegame(Stream *in);
    virtual void WriteToSavegame(Stream *out) const;

// TODO: these members are currently public; hide them later
public:
    int32_t MinValue;
    int32_t MaxValue;
    int32_t Value;
    int32_t BgImage;
    int32_t HandleImage;
    int32_t HandleOffset;
    bool    IsMousePressed;

private:
    // The following variables are not persisted on disk
    // Cached coordinates of slider handle
    Rect    _cachedHandle;
};

} // namespace Common
} // namespace AGS

extern std::vector<AGS::Common::GUISlider> guislider;
extern int numguislider;

#endif // __AC_GUISLIDER_H
