#include "ui_element.h"

#include <cassert>

namespace recompui {

static Rml::Unit to_rml(Unit unit) {
    switch (unit) {
    case Unit::Float:
        return Rml::Unit::NUMBER;
    case Unit::Dp:
        return Rml::Unit::DP;
    case Unit::Percent:
        return Rml::Unit::PERCENT;
    default:
        return Rml::Unit::UNKNOWN;
    }
}

Element::Element(Rml::Element *base) {
    assert(base != nullptr);

    this->base = base;
    this->parent = nullptr;
    this->owner = false;
}

Element::Element(Element *parent) {
    assert(parent != nullptr);

    this->base = parent->base->AppendChild(parent->base->GetOwnerDocument()->CreateElement(get_rml_element_name()));
    this->parent = parent;
    this->owner = true;
}

Element::~Element() {
    if (owner) {
        base->GetParentNode()->RemoveChild(base);
    }
}

Rml::String Element::get_rml_element_name() const {
    return "div";
}

void Element::set_position(Position position) {
    switch (position) {
    case Position::Absolute:
        base->SetProperty(Rml::PropertyId::Position, Rml::Style::Position::Absolute);
        break;
    case Position::Relative:
        base->SetProperty(Rml::PropertyId::Position, Rml::Style::Position::Relative);
        break;
    default:
        assert(false && "Unknown position.");
        break;
    }
}

void Element::set_left(float left, Unit unit) {
    base->SetProperty(Rml::PropertyId::Left, Rml::Property(left, to_rml(unit)));
}

void Element::set_top(float top, Unit unit) {
    base->SetProperty(Rml::PropertyId::Top, Rml::Property(top, to_rml(unit)));
}

void Element::set_right(float right, Unit unit) {
    base->SetProperty(Rml::PropertyId::Right, Rml::Property(right, to_rml(unit)));
}

void Element::set_bottom(float bottom, Unit unit) {
    base->SetProperty(Rml::PropertyId::Bottom, Rml::Property(bottom, to_rml(unit)));
}

void Element::set_width(float width, Unit unit) {
    base->SetProperty(Rml::PropertyId::Width, Rml::Property(width, to_rml(unit)));
}

void Element::set_height(float height, Unit unit) {
    base->SetProperty(Rml::PropertyId::Height, Rml::Property(height, to_rml(unit)));
}

void Element::set_border_width(float width, Unit unit) {
    Rml::Property property(width, to_rml(unit));
    base->SetProperty(Rml::PropertyId::BorderTopWidth, property);
    base->SetProperty(Rml::PropertyId::BorderBottomWidth, property);
    base->SetProperty(Rml::PropertyId::BorderLeftWidth, property);
    base->SetProperty(Rml::PropertyId::BorderRightWidth, property);
}

void Element::set_border_radius(float radius, Unit unit) {
    Rml::Property property(radius, to_rml(unit));
    base->SetProperty(Rml::PropertyId::BorderTopLeftRadius, property);
    base->SetProperty(Rml::PropertyId::BorderTopRightRadius, property);
    base->SetProperty(Rml::PropertyId::BorderBottomLeftRadius, property);
    base->SetProperty(Rml::PropertyId::BorderBottomRightRadius, property);
}

void Element::set_background_color(const Color &color) {
    Rml::Property property(Rml::Colourb(color.r, color.g, color.b, color.a), Rml::Unit::COLOUR);
    base->SetProperty(Rml::PropertyId::BackgroundColor, property);
}

void Element::set_border_color(const Color &color) {
    Rml::Property property(Rml::Colourb(color.r, color.g, color.b, color.a), Rml::Unit::COLOUR);
    base->SetProperty(Rml::PropertyId::BorderTopColor, property);
    base->SetProperty(Rml::PropertyId::BorderBottomColor, property);
    base->SetProperty(Rml::PropertyId::BorderLeftColor, property);
    base->SetProperty(Rml::PropertyId::BorderRightColor, property);
}

void Element::set_cursor(Cursor cursor) {
    switch (cursor) {
    case Cursor::None:
        assert(false && "Unimplemented.");
        break;
    case Cursor::Pointer:
        base->SetProperty(Rml::PropertyId::Cursor, Rml::Property("pointer", Rml::Unit::STRING));
        break;
    default:
        assert(false && "Unknown cursor.");
        break;
    }
}

void Element::set_opacity(float opacity) {
    base->SetProperty(Rml::PropertyId::Opacity, Rml::Property(opacity, Rml::Unit::NUMBER));
}

void Element::set_justify_content(JustifyContent justify_content) {
    switch (justify_content) {
    case JustifyContent::SpaceBetween:
        break;
    default:
        assert(false && "Unknown justify content.");
        break;
    }
}

};