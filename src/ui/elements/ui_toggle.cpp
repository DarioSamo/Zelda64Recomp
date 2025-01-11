#include "ui_toggle.h"

namespace recompui {

    Toggle::Toggle(Element *parent) : Element(parent) {
        set_width(162.0f);
        set_height(72.0f);
        set_border_radius(36.0f);
        set_opacity(0.9f);
        set_background_color({ 0, 0, 0, 0 });
        set_cursor(Cursor::Pointer);
        set_border_width(2.0f);
        set_border_color({ 34, 177, 76, 255 });

        floater = std::make_unique<Element>(this);
        floater->set_position(Position::Relative);
        floater->set_top(2.0f);
        floater->set_left(4.0f);
        floater->set_width(80.0f);
        floater->set_height(64.0f);
        floater->set_border_radius(32.0f);
        floater->set_background_color({ 68, 206, 120, 255 });
    }

    Rml::String Toggle::get_rml_element_name() const {
        return "button";
    }

};