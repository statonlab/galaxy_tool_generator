<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_requirements_container() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_requirements_container($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > requirements > container');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_requirements_container(&$form) {
  unset($form['validation']);
  unset($form['display']);

  // TODO
  $form = array_merge($form, get_edit_component_base_form_elements($form, 'container'));

  // TODO
  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['type'] = [
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('This value describes the type of container that the tool 
      may be executed in and currently must be <span style="color: #FF5666">docker</span>'),
    // TODO: need a full list of options.
    '#options' => drupal_map_assoc([
      'docker',
    ]),
    '#default_value' => 'container',
    '#required' => TRUE,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}