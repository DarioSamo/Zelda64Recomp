#pragma once

#include "ui_element.h"

namespace recompui {

    class Container : public Element {
    public:
        Container(FlexDirection direction, JustifyContent justify_content, Element *parent);
    };

} // namespace recompui
