<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_boolean() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_boolean($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_type_boolean', $component, 'tool > inputs > param (type: boolean)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_boolean(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

  // form field to edit attributes, available attributes includes:
  $form = array_merge($form, get_param_type_base_form_elements($form, 'boolean'));
  $form['extra']['attributes']['checked'] = [
    '#type' => 'radios',
    '#title' => t('Checked'),
    '#description' => t('Set to <span style="color: #FF5666">true</span> if the 
        <span style="color: #FF5666">boolean</span> parameter should be checked 
        (or <span style="color: #FF5666">true</span>) by default.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
  $form['extra']['attributes']['truevalue'] = [
    '#type' => 'textfield',
    '#title' => t('True value'),
    '#description' => t('The parameter value in the Cheetah template if the 
      parameter is <span style="color: #FF5666">true</span> or checked by the user. 
      Only valid if <span style="color: #FF5666">type</span> is <span style="color: #FF5666">boolean</span>.'),
    '#default_value' => 'NO_ARGUMENT_YES',
  ];
  $form['extra']['attributes']['falsevalue'] = [
    '#type' => 'textfield',
    '#title' => t('False value'),
    '#description' => t('The parameter value in the Cheetah template if the 
      parameter is <span style="color: #FF5666">false</span> or checked by the user. 
      Only valid if <span style="color: #FF5666">type</span> is <span style="color: #FF5666">boolean</span>.'),
    '#default_value' => 'NO_ARGUMENT_NO',
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}