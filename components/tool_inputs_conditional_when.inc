<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_conditional_when() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_conditional_when($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_conditional_when', $component, 'tool > inputs > conditional > when');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_conditional_when(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'when'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('Value for the tool form test parameter corresponding to this when block.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}