<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_component_template()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_component_template($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('component_template', $component, '');
}

/**
 * Implement edit command function.
 */
function edit_component_component_template(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'xml_tag'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes'][''] = [];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}