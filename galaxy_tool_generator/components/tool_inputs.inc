<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > inputs');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'inputs'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['action'] = [
    '#type' => 'textfield',
    '#title' => t('Action'),
    '#description' => t('URL used by data source tools.'),
  ];
  $form['extra']['attributes']['check_values'] = [
    '#type' => 'radios',
    '#title' => t('Check values'),
    '#description' => t('Set to  <span style="color: #FF5666">false</span> to 
        disable parameter checking in data source tools.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
  $form['extra']['attributes']['method'] = [
    '#type' => 'radios',
    '#title' => t('Method'),
    '#description' => t('Data source HTTP action (e.g. <span style="color: #FF5666">get</span> 
        or <span style="color: #FF5666">put</span>) to use.'),
    '#options' => drupal_map_assoc([
      'get',
      'put',
    ]),
  ];
  $form['extra']['attributes']['target'] = [
    '#type' => 'textfield',
    '#title' => t('Target'),
    '#description' => t('UI link target to use for data source tools 
        (e.g. <span style="color: #FF5666">_top</span>).'),
  ];
  $form['extra']['attributes']['nginx_upload'] = [
    '#type' => 'radios',
    '#title' => t('Nginx upload'),
    '#description' => t('This boolean indicates if this is an upload tool or not.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}