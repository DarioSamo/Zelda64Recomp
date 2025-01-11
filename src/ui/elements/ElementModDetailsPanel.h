#ifndef RECOMPUI_ELEMENT_MOD_DETAILS_PANEL_H
#define RECOMPUI_ELEMENT_MOD_DETAILS_PANEL_H

#include "common.h"
#include "librecomp/mods.hpp"
#include "ui_toggle.h"

namespace recompui {

class ElementModDetailsPanel : public Rml::Element {
public:
	ElementModDetailsPanel(const Rml::String& tag);
	virtual ~ElementModDetailsPanel();
    void SetModDetails(const recomp::mods::ModDetails& details);
private:
    recomp::mods::ModDetails cur_details;
    Rml::Element* thumbnail_el;
    Rml::Element* title_el;
    Rml::Element* authors_el;
    Rml::Element* version_el;
    Rml::Element* description_el;
    Rml::Element* configure_button;
    Rml::Element* delete_button;
    std::unique_ptr<recompui::Toggle> enable_toggle;
};

} // namespace recompui
#endif
