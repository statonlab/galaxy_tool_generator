<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_requirements_requirement() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_requirements_requirement($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  // TODO
  return get_component_render_array('tool_inputs', $component, 'tool > requirements > requirement');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_requirements_requirement(&$form) {
  unset($form['validation']);
  unset($form['display']);

  // TODO
  $form = array_merge($form, get_edit_component_base_form_elements($form, 'requirement'));

  // TODO
  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['type'] = [
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('This value defines the which type of the 3rd party module required by this tool.'),
    // TODO: need a full list of options.
    '#options' => drupal_map_assoc([
      'set_environment',
      'package',
    ]),
    '#default_value' => 'package',
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['version'] = [
    '#type' => 'textfield',
    '#title' => t('Version'),
    '#description' => t('For package type requirements this value defines a 
      specific version of the tool dependency.'),
  ];
}