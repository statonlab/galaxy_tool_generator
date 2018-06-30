<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_requirements() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_requirements($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > requirements');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_requirements(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'requirements'));

  // form field to edit attributes, available attributes for command includes:
  // This tag does not have any attributes.

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}