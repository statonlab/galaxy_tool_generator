<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_help() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_help($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_command', $component, 'tool > help');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_help(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'help'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('This tag set includes all of the necessary details of 
      how to use the tool. This tag set should be included as the next to the 
      last tag set, before citations, in the tool config. Tool help is written 
      in <span style="color: #FF5666">reStructuredText</span>. Included here is 
      only an overview of a subset of features. For more information see 
      http://docutils.sourceforge.net/docs/ref/rst/restructuredtext.html.'),
    '#required' => TRUE,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}