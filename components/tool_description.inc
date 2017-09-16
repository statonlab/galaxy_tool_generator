<?php

/**
 * @file
 * description component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_description() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_description().
 */
function _webform_render_tool_description($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_description', $component, 'tool > description');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_description(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form));

  // form field to edit attributes, available attributes for command includes:
  //      NA (this tag does not include any attributes).
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('The value will be placed within the XML tag pair.'),
    '#required' => TRUE,
  ];
}