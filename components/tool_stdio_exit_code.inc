<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_stdio_exit_code()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_stdio_exit_code($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('component_template', $component, 'tool > stdio > exit_code');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_stdio_exit_code(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'exit_code'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['range'] = [
        '#type' => 'textfield',
        '#title' => t('Range'),
        '#description' => t('This indicates the range of exit codes to check. The range can be one of the following: 
            <span style="color: #FF5666">n, m:n, m:, :n</span>, for example, <code>2, 3:5, 3:, :5</code>'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['level'] = [
        '#type' => 'radios',
        '#title' => t('Error level'),
        '#description' => t('This indicates the error level of the exit code.'),
        '#options' => drupal_map_assoc([
            'warning',
            'fatal',
        ]),
        '#default_value' => 'warning',
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['description'] = [
        '#type' => 'textarea',
        '#title' => t('Description'),
        '#description' => t('This is an optional description of the error that corresponds to the exit code.'),
        '#required' => TRUE,
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}