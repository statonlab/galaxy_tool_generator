<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_conditional() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_conditional($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_conditional', $component, 'tool > inputs > conditional');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_conditional(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this element.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('Human readable description for the conditional, 
      unused in the Galaxy UI currently.'),
  ];
}