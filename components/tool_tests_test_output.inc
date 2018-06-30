<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_tests_test_output() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_tests_test_output($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_tests_test_output', $component, 'tool > tests > test > output');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_tests_test_output(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'output'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('This value is the same as the value of the 
        <span style="color: #FF5666">name</span> attribute of the 
        <span style="color: #FF5666">data</span> tag set contained within the tool’s 
        <span style="color: #FF5666">outputs</span> tag set.'),
  ];
  $form['extra']['attributes']['file'] = [
    '#type' => 'textfield',
    '#title' => t('File'),
    '#description' => t('If specified, this value is the name of the output file 
      stored in the target <span style="color: #FF5666">test-data</span> directory 
      which will be used to compare the results of executing the tool via the 
      functional test framework.'),
  ];
  $form['extra']['attributes']['ftype'] = [
    '#type' => 'textfield',
    '#title' => t('ftype'),
    '#description' => t('If specified, this value will be checked against the 
      corresponding output’s data type. If these do not match, the test will fail.'),
  ];
  $form['extra']['attributes']['sort'] = [
    '#type' => 'radios',
    '#title' => t('Sort'),
    '#description' => t('This flag causes the lines of the output to be sorted 
      before they are compared to the expected output. 
      This could be useful for non-deterministic output.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('An alias for <span style="color: #FF5666">file</span>'),
  ];
  $form['extra']['attributes']['md5'] = [
    '#type' => 'textfield',
    '#title' => t('md5'),
    '#description' => t('If specified, the target output’s MD5 hash should match 
      the value specified here. For large static files it may be inconvenient to 
      upload the entry file and this can be used instead.'),
  ];
  $form['extra']['attributes']['checksum'] = [
    '#type' => 'textfield',
    '#title' => t('checksum'),
    '#description' => t('If specified, the target output’s checksum should match 
      the value specified here. This value should have the form <span style="color: #FF5666">hash_type:hash_value</span> 
      (e.g. <span style="color: #FF5666">sha1:8156d7ca0f46ed7abac98f82e36cfaddb2aca041</span>). 
      For large static files it may be inconvenient to upload the entiry file and this can be used instead.'),
  ];
  $form['extra']['attributes']['compare'] = [
    '#type' => 'radios',
    '#title' => t('Compare'),
    '#description' => t('Type of comparison to use when comparing test generated 
    output files to expected output files.'),
    '#options' => drupal_map_assoc([
      'diff',
      're_match',
      'sim_size',
      're_match_multiline',
      'contains',
    ]),
    '#default_value' => 'diff',
  ];
  $form['extra']['attributes']['lines_diff'] = [
    '#type' => 'textfield',
    '#title' => t('lines_diff'),
    '#description' => t('If <span style="color: #FF5666">compare</span> is set to 
        <span style="color: #FF5666">diff</span>, the number of lines of difference 
        to allow (each line with a modification is a line added and a line 
        removed so this counts as two lines).'),
  ];
  $form['extra']['attributes']['decompress'] = [
    '#type' => 'textfield',
    '#title' => t('decompress'),
    '#description' => t('If <span style="color: #FF5666">compare</span> is set to 
        <span style="color: #FF5666">diff</span>, attempt to decompress both produced 
        output and expected output files if needed before performing the diff. 
        This flag is useful for testing gzipped outputs that are non-deterministic 
        despite having deterministic decompressed contents. This is available in 
        Galaxy 17.05+ and was introduced in' . l('pull request #3550.', 'https://github.com/galaxyproject/galaxy/pull/3550')),
  ];
  $form['extra']['attributes']['delta'] = [
    '#type' => 'textfield',
    '#title' => t('delta'),
    '#description' => t('If <span style="color: #FF5666">compare</span> is set to 
        <span style="color: #FF5666">sim_size</span>, this is the number of bytes different allowed.')
  ];
  $form['extra']['attributes'][''] = [];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}