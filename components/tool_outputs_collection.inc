<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_collection() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_collection($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_collection', $component, 'tool > outputs > collection');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_collection(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'collection'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this output. This <span style="color: #FF5666">name</span> is used as the Cheetah 
      variable containing the Galaxy assigned output path in <span style="color: #FF5666">command</span> 
      and <span style="color: #FF5666">configfile</span> elements. 
      The name should not contain pipes or periods (e.g. <span style="color: #FF5666">.</span>).'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['type'] = [
    '#type' => 'radios',
    '#title' => t('Type'),
    '#description' => t('Collection type for output'),
    '#options' => drupal_map_assoc([
      'paired',
      'list',
      'list:paired',
    ]),
  ];
  $form['extra']['attributes']['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('This will be the name of the history item for the output 
        data set. The string can include structure like <span style="color: #FF5666"><code>
        ${&lt;some param name&gt;.&lt;some attribute&gt;}</code></span>, as discussed 
        for command line parameters in the <span style="color: #FF5666">&lt;command&gt;</span> 
        tag set section above. The default label is <span style="color: #FF5666">${tool.name}</span> 
        on <span style="color: #FF5666">${on_string}</span>.')
  ];
  $form['extra']['attributes']['format_source'] = [
    '#type' => 'textfield',
    '#title' => t('Format source'),
    '#description' => t('This is the name of input collection or dataset to derive 
      output dataset collection’s element’s format/datatype from.	False type_source	')
  ];
  $form['extra']['attributes']['type_source'] = [
    '#type' => 'textfield',
    '#title' => t('Type source'),
    '#description' => t('This is the name of input collection to derive collection’s 
      type (e.g. <span style="color: #FF5666">collection_type</span>) from.')
  ];
  $form['extra']['attributes']['structured_like'] = [
    '#type' => 'textfield',
    '#title' => t('Structured like'),
    '#description' => t('This is the name of input collection or dataset to derive 
      “structure” of the output from (output element count and identifiers). For instance, 
      if the referenced input has three ordered items with identifiers 
      <span style="color: #FF5666">sample1</span>, 
      <span style="color: #FF5666">sample2</span>, and 
      <span style="color: #FF5666">sample3</span>'),
  ];
  $form['extra']['attributes']['inherit_format'] = [
    '#type' => 'radios',
    '#title' => t('Inherit format'),
    '#description' => t('If <span style="color: #FF5666">structured_like</span> is set, 
        inherit format of outputs from format of corresponding input.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}