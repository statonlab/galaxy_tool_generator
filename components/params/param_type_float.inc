<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_float()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_float($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs_param_type_float', $component, 'tool > inputs > param (type: float)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_float(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

    // form field to edit attributes, available attributes includes:
    $form = array_merge($form, get_param_type_base_form_elements($form, 'float'));
    $form['extra']['attributes']['value'] = [
        '#type' => 'textfield',
        '#title' => t('Value'),
        '#description' => t('The default value for this parameter.'),
    ];
    $form['extra']['attributes']['min'] = [
        '#type' => 'textfield',
        '#title' => t('Min'),
        '#description' => t('Minimum valid parameter value - only valid 
        when <span style="color: #FF5666">type</span> is <span style="color: #FF5666">integer</span> 
        or <span style="color: #FF5666">float</span>.'),
    ];
    $form['extra']['attributes']['max'] = [
        '#type' => 'textfield',
        '#title' => t('Max'),
        '#description' => t('Maximum valid parameter value - only valid 
        when <span style="color: #FF5666">type</span> is <span style="color: #FF5666">integer</span> 
        or <span style="color: #FF5666">float</span>.'),
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}