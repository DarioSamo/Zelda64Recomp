#include "ui_layout.h"

#include <cassert>

namespace recompui {

Layout::Layout(Direction direction, Element *parent) : Element(parent) {
    switch (direction) {
    case Direction::Horizontal:
        base->SetProperty(Rml::PropertyId::FlexDirection, Rml::Property(Rml::Style::FlexDirection::Row))
        break;
    case Direction::Vertical:
        base->SetProperty(Rml::PropertyId::FlexDirection, Rml::Property(Rml::Style::FlexDirection::Column))
        break;
    default:
        assert(false && "Unknown layout direction");
        return;
    }
}

Rml::String Layout::get_rml_element_name() const {
    return "div";
}

};