<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_change_format() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_change_format($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > outputs > data > change_format');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_change_format(&$form) {
  unset($form['validation']);
  unset($form['display']);

  // TODO
  $form = array_merge($form, get_edit_component_base_form_elements($form, 'change_format'));

  // TODO
  // form field to edit attributes, available attributes for command includes:
  // this tag is a container tag and therefore has no attributes.
}