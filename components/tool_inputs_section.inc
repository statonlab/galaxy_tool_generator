<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_section()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_section($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs_section', $component, 'tool > inputs > section');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_section(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'section'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['name'] = [
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#description' => t('The internal key used for the section.'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['title'] = [
        '#type' => 'textfield',
        '#title' => t('Title'),
        '#description' => t('Human readable label for the section.'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['expanded'] = [
        '#type' => 'radios',
        '#title' => t('Expanded'),
        '#description' => t('Whether the section should be expanded by default or 
      not. If not, the default set values are used.'),
        '#options' => drupal_map_assoc([
            'True',
            'False',
        ]),
    ];
    $form['extra']['attributes']['help'] = [
        '#type' => 'textarea',
        '#title' => t('Help'),
        '#description' => t('Short help description for section, rendered just below the section.'),
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}