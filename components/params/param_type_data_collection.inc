<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_data_collection() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_data_collection($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_type_data_collection', $component, 'tool > inputs > param (type: data_collection)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_data_collection(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

  // form field to edit attributes, available attributes for command includes:
  $form = array_merge($form, get_param_type_base_form_elements($form, 'data_collection'));
  $form['extra']['attributes']['format'] = [
    '#type' => 'textfield',
    '#title' => t('Format'),
    '#description' => t('Only if <span style="color: #FF5666">type</span> 
        attribute value is <span style="color: #FF5666">data</span> or 
        <span style="color: #FF5666">data_collection</span> - the list of 
        supported data formats is contained in the ' . l('/config/datatypes_conf.xml.sample', 'https://github.com/galaxyproject/galaxy/blob/dev/config/datatypes_conf.xml.sample') .
        ' file. Use the file extension.'),
  ];
  $form['extra']['attributes']['collection_type'] = [
    '#type' => 'radios',
    '#title' => t('Collection type'),
    '#description' => t('This is only valid if <span style="color: #FF5666">type
        </span>is <span style="color: #FF5666">data_collection</span>. 
        Restrict the kind of collection that can be consumed by this parameter 
        (e.g. <span style="color: #FF5666">paired, list:paired, list</span>). 
        Multiple such collection types can be specified here as a comma separated list.'),
    '#options' => drupal_map_assoc([
      'paired',
      'list',
      'list:paired',
    ]),
    '#default_value' => 'list',
  ];


  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}