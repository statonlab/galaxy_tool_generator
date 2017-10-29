<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_text()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_text($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs_param_type_text', $component, 'tool > inputs > param (type: text)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_text(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

    // form field to edit attributes, available attributes for command includes:
    $form = array_merge($form, get_param_type_base_form_elements($form, 'text'));
    $form['extra']['attributes']['area'] = [
        '#type' => 'radios',
        '#title' => t('Area'),
        '#description' => t('Boolean indicating if this should be rendered as a 
      one line text box (if <span style="color: #FF5666">false</span>) or a 
      multi-line text area (if <span style="color: #FF5666">true</span>).'),
        '#options' => drupal_map_assoc([
            'False',
            'True',
        ]),
    ];
    $form['extra']['attributes']['value'] = [
        '#type' => 'textfield',
        '#title' => t('Value'),
        '#description' => t('The default value for this parameter.'),
    ];
    $form['extra']['attributes']['size'] = [
        '#type' => 'textfield',
        '#title' => t('size'),
        '#description' => t('Used only if <span style="color: #FF5666">type</span> attribute 
      value is text. To create a multi-line text box add an <span style="color: #FF5666">area="True"</span>
      attribute to the param tag. This can be one dimensional (e.g. <span style="color: #FF5666">size="40"</span>) or 
      two dimensional (e.g. <span style="color: #FF5666">size="5x25"</span>).')
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}