<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_stdio()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_stdio($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('component_template', $component, 'tool > stdio');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_stdio(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'stido'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes'][''] = [];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}