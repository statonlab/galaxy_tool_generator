<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_component_template() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_component_template($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('component_template', $component, '');
}

/**
 * Implement edit command function.
 */
function edit_component_component_template(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes'][''] = [];
}