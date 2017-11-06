<?php

/**
 * @file
 * version_command component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_version_command() {
  return get_webform_defaults_component_base_array();
}


/**
 * Implements _webform_render_version_command().
 */
function _webform_render_tool_version_command($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_version_command', $component, 'tool > version_command');
}

/**
 * edit component: version_command
 */
function edit_component_tool_version_command(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'version_command'));

  // form field to edit attributes, available attributes for command includes:
  //      interpreter
  $form['extra']['attributes']['interpreter'] = [
    '#type' => 'textfield',
    '#title' => t('Interpreter'),
    '#description' => t('Deprecated: Prefix the version command with an <span style="color: #FF5666">
        interpreter</span> and the tool directory in order to execute a script shipped with the tool. 
        It is better to just use <span style="color: #FF5666">&lt;interpreter&gt; $__tool_directory__/&lt;script_name&gt;</span>.'),
  ];
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('The value will be placed within the XML tag pair.'),
    '#required' => TRUE,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}