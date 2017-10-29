<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_change_format_when()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_change_format_when($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs', $component, 'tool > outputs > data > change_format > when');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_change_format_when(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    // TODO
    $form = array_merge($form, get_edit_component_base_form_elements($form, 'when'));

    // TODO
    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['input'] = [
        '#type' => 'textfield',
        '#title' => t('Input'),
        '#description' => t('This attribute should be the name of the desired <span style="color: #FF5666">input</span> parameter'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['value'] = [
        '#type' => 'textfield',
        '#title' => t('Value'),
        '#description' => t('This must be a possible value of the <span style="color: #FF5666">input</span> parameter, 
        or of the deprecated <span style="color: #FF5666">input_dataset</span>‘s attribute.'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['format'] = [
        '#type' => 'textfield',
        '#title' => t('Format'),
        '#description' => t('This value must be a supported data type. See ' .
            l('/config/datatypes_conf.xml.sample', 'https://github.com/galaxyproject/galaxy/blob/dev/config/datatypes_conf.xml.sample') .
            ' for a list of supported formats.'),
        '#required' => TRUE,
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}