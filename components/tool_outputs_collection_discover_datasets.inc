<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_collection_discover_datasets() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_collection_discover_datasets($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_collection_discover_datasets', $component, 'tool > outputs > collection > discover_datasets');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_collection_discover_datasets(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'discover_datasets'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['from_provided_meta'] = [
    '#type' => 'radios',
    '#title' => t('From provided metadata'),
    '#description' => t('Indicate that dataset filenames should simply be read 
      from the provided metadata file (e.g. galaxy.json). If this is set - pattern 
      and sort must not be set.	'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
  ];
  $form['extra']['attributes']['pattern'] = [
    '#type' => 'textfield',
    '#title' => t('Pattern'),
    '#description' => t('Regular expression used to find filenames and 
      parse dynamic properties.')
  ];
  $form['extra']['attributes']['directory'] = [
    '#type' => 'textfield',
    '#title' => t('Directory'),
    '#description' => t('Directory (relative to working directory) to search for files.'),
  ];
  $form['extra']['attributes']['format'] = [
    '#type' => 'textfield',
    '#title' => t('Format'),
    '#description' => t('Format (or datatype) of discovered datasets (an alias 
      with <span style="color: #FF5666">ext</span>).'),
  ];
  $form['extra']['attributes']['ext'] = [
    '#type' => 'textfield',
    '#title' => t('Ext'),
    '#description' => t('Format (or datatype) of discovered datasets (an alias 
      with <span style="color: #FF5666">format</span>).'),
  ];
  $form['extra']['attributes']['visible'] = [
    '#type' => 'radios',
    '#title' => t('Visible'),
    '#description' => t('Indication if this dataset is visible in output history. 
      This defaults to <span style="color: #FF5666">false</span>, but probably 
      shouldn\'t - be sure to set to <span style="color: #FF5666">true</span> if that is your intention.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
    '#default_value' => 'false',
  ];
  $form['extra']['attributes']['assign_primary_output'] = [
    '#type' => 'radios',
    '#title' => t('Assign primary output'),
    '#description' => t('Replace the primary dataset described by the parameter 
      <span style="color: #FF5666">data</span> parameter with the first output discovered.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}