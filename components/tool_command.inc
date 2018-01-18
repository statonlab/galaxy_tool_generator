<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_command() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_command($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_command', $component, 'tool > command');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_command(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'command'));

  // form field to edit attributes, available attributes for command includes:
  //      detect_errors
  //      strict
  //      interpreter
  $form['extra']['attributes']['detect_errors'] = [
    '#type' => 'radios',
    '#title' => t('Detect errors'),
    '#description' => t(''),
    '#options' => drupal_map_assoc([
      'default',
      'exit_code',
      'aggressive',
    ]),
  ];
  $form['extra']['attributes']['strict'] = [
    '#type' => 'radios',
    '#title' => t('Strict'),
    '#description' => t('This boolean forces the <span style="color: #FF5666">#set -e</span> 
        directive on in shell scripts - so that in a multi-part command if any 
        part fails the job exits with a non-zero exit code. This is enabled by 
        default for tools with <span style="color: #FF5666">profile>=16.04</span> 
        and disabled on legacy tools.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
  $form['extra']['attributes']['interpreter'] = [
    '#type' => 'textfield',
    '#title' => t('Interpreter'),
    '#description' => t('Older tools may define an <span style="color: #FF5666">interpreter</span>
        attribute on the command, but this is deprecated and using the <span style="color: #FF5666">
        $__tool_directory__</span> variable is superior.'),
  ];
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('The shell script that will be added to the command section. It will
      probably be easier to write your shell script on a shell script editor and then copy and
      paste it to here.'),
    '#required' => TRUE,
    '#rows' => 30,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}