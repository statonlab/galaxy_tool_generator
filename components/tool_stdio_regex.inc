<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_stdio_regex() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_stdio_regex($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_stdio_regex', $component, 'tool > stdio > regex');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_stdio_regex(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'regex'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['source'] = [
    '#type' => 'radios',
    '#title' => t('Source'),
    '#description' => t('This tells whether the regular expression should be matched against stdout, stderr, or both. 
            If this attribute is missing or is incorrect, then both stdout and stderr will be checked.'),
    '#options' => drupal_map_assoc([
      'both',
      'stdout',
      'stderr',
    ]),
    '#default_value' => 'both',
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['match'] = [
    '#type' => 'textfield',
    '#title' => t('Match'),
    '#description' => t(' This is the regular expression that will be used to match against stdout and/or stderr. 
            If the tag does not contain the match attribute, then the tag will be ignored. The regular expression can 
            be any valid Python regular expression. All regular expressions are performed case insensitively.'),
  ];
  $form['extra']['attributes']['level'] = [
    '#type' => 'radios',
    '#title' => t('Level'),
    '#description' => t('This works very similarly to the tag, except that, when a regular expression matches against 
            its source, the description is added to the beginning of the source.'),
    '#options' => drupal_map_assoc([
      'log',
      'warning',
      'fatal',
    ]),
    '#default_value' => 'warning',
  ];
  $form['extra']['attributes']['description'] = [
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#description' => t('Just like its <span style="color: #FF5666">exit_code</span> counterpart, this is an optional 
            description of the regular expression that has matched.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}