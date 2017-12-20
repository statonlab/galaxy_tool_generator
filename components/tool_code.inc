<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_code() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_code($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_code', $component, 'tool > code');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_code(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'code'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['file'] = [
    '#type' => 'textfield',
    '#title' => t('file'),
    '#description' => t('This value is the name of the executable code file, and is 
      called in the <span style="color: #FF5666"><code>exec_before_process()</code></span>, 
      <span style="color: #FF5666"><code>exec_before_job()</code></span>, 
      <span style="color: #FF5666"><code>exec_after_process()</code></span> and 
      <span style="color: #FF5666"><code>exec_after_job()</code></span> methods.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}