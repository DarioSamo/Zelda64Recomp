#include "ElementModDetailsPanel.h"
#include "presets.h"
#include "librecomp/mods.hpp"

#include <string>

#define MOD_DETAILS_BEM "mod-details"
#define MOD_DETAILS_TOGGLE_BEM "mod-details-toggle"

namespace recompui {

static const std::string cls_base = BLOCK(MOD_DETAILS_BEM);
static const std::string cls_header = EL(MOD_DETAILS_BEM, "header");
static const std::string cls_thumbnail_container = EL(MOD_DETAILS_BEM, "thumbnail-container");
static const std::string cls_thumbnail = EL(MOD_DETAILS_BEM, "thumbnail");
static const std::string cls_header_details = EL(MOD_DETAILS_BEM, "header-details");
static const std::string cls_title = EL(MOD_DETAILS_BEM, "title");
static const std::string cls_version = EL(MOD_DETAILS_BEM, "version");
static const std::string cls_body = EL(MOD_DETAILS_BEM, "body");
static const std::string cls_buttons = EL(MOD_DETAILS_BEM, "buttons");
static const std::string cls_authors = EL(MOD_DETAILS_BEM, "authors");
static const std::string cls_description = EL(MOD_DETAILS_BEM, "description");
static const std::string cls_spacer = EL(MOD_DETAILS_BEM, "spacer");
static const std::string cls_toggle = BLOCK(MOD_DETAILS_TOGGLE_BEM);
static const std::string cls_toggle_border = EL(MOD_DETAILS_TOGGLE_BEM, "border");

ElementModDetailsPanel::ElementModDetailsPanel(const Rml::String& tag) : Rml::Element(tag)
{
    SetAttribute("recomp-store-element", true);
    Rml::ElementDocument *doc = GetOwnerDocument();
    SetClass(cls_base, true);

    {
        Rml::Element *header_el = add_div_with_class(doc, this, cls_header);
        {
            Rml::Element *thumbnail_container_el = add_div_with_class(doc, header_el, cls_thumbnail_container);
            {
                thumbnail_el = add_div_with_class(doc, thumbnail_container_el, cls_thumbnail);
            } // thumbnail_container_el

            Rml::Element *header_details_el = add_div_with_class(doc, header_el, cls_header_details);
            {
                title_el = add_div_with_class(doc, header_details_el, cls_title);
                version_el = add_div_with_class(doc, header_details_el, cls_version);
            } // header_details_el
        }
        Rml::Element* body_el = add_div_with_class(doc, this, cls_body);
        {
            description_el = add_div_with_class(doc, body_el, cls_description);
            authors_el = add_div_with_class(doc, body_el, cls_authors);

            Rml::Element *buttons_el = add_div_with_class(doc, body_el, cls_buttons);
            {
                recompui::Element buttons_el_compat(buttons_el);
                enable_toggle = std::make_unique<recompui::Toggle>(&buttons_el_compat);
                configure_button = add_button(doc, buttons_el, "Configure", ButtonVariant::Secondary);
                delete_button = add_button(doc, buttons_el, "Erase", ButtonVariant::Secondary);
            } // buttons_el
        } // body_el
    }
}

ElementModDetailsPanel::~ElementModDetailsPanel()
{
}

void ElementModDetailsPanel::SetModDetails(const recomp::mods::ModDetails& details) {
    cur_details = details;

    title_el->SetInnerRML(cur_details.mod_id);
    version_el->SetInnerRML(cur_details.version.to_string());

    std::string authors_str = "<i>Authors</i>:";
    bool first = true;
    for (const std::string& author : details.authors) {
        authors_str += (first ? " " : ", ") + author;
        first = false;
    }
    authors_el->SetInnerRML(authors_str);
    description_el->SetInnerRML("Placeholder description. Some long text to make sure that wrapping is working correctly. Yet more text and so on.");

    DirtyLayout();
}

} // namespace Rml
