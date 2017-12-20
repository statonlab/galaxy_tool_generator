<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_options_filter() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_options_filter($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_options_filter', $component, 'tool > inputs > param > options > filter');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_options_filter(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'filter'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['type'] = [
    '#type' => 'select',
    '#title' => t('Type'),
    '#description' => t('These values are defined in the module ' .
      l('/lib/galaxy/tools/parameters/dynamic_options.py', 'https://github.com/galaxyproject/galaxy/blob/master/lib/galaxy/tools/parameters/dynamic_options.py') .
      ' in the filter_types dictionary'),
    '#options' => drupal_map_assoc([
      'data_meta',
      'param_value',
      'static_value',
      'unique_value',
      'multiple_splitter',
      'attribute_value_splitter',
      'add_value',
      'remove_value',
      'sort_by',
    ]),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['column'] = [
    '#type' => 'textfield',
    '#title' => t('Column'),
    '#description' => t('Column targeted by this filter - this attribute is 
      unused and invalid if <span style="color: #FF5666">type</span> is 
      <span style="color: #FF5666">add_value</span> or 
      <span style="color: #FF5666">remove_value</span>. 
      This can be a column index or a column name.'),
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name displayed for value to add (only used with 
      <span style="color: #FF5666;">type</span> of <span style="color: #FF5666">add_value</span>).'),
  ];
  $form['extra']['attributes']['ref'] = [
    '#type' => 'textfield',
    '#title' => t('Reference file'),
    '#description' => t('The attribute name of the reference file (tool data) or 
      input dataset. Only used when <span style="color: #FF5666">type</span> is 
      <span style="color: #FF5666">data_meta</span> (required), 
      <span style="color: #FF5666">param_value</span> (required), or 
      <span style="color: #FF5666">remove_value</span> (optional).')
  ];
  $form['extra']['attributes']['key'] = [
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#description' => t('When <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">data_meta</span>, 
        <span style="color: #FF5666">param_value</span>, or 
        <span style="color: #FF5666">remove_value</span> - this is the name of 
        the metadata key to filter by.'),
  ];
  $form['extra']['attributes']['multiple'] = [
    '#type' => 'radios',
    '#title' => t('Multiple'),
    '#description' => t('For types <span style="color: #FF5666">data_meta</span> and 
        <span style="color: #FF5666">remove_value</span>, whether option values are multiple. 
        Columns will be split by separator. Defaults to <span style="color: #FF5666">false</span>.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ])
  ];
  $form['extra']['attributes']['separator'] = [
    '#type' => 'textfield',
    '#title' => t('Separator'),
    '#description' => t('When <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">data_meta</span>, 
        <span style="color: #FF5666">multiple_splitter</span>, or 
        <span style="color: #FF5666">remove_value</span> - this is used to split 
        one value into multiple parts. When <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">data_meta</span> or 
        <span style="color: #FF5666">remove_value</span> this is only used if 
        <span style="color: #FF5666">multiple</span> is set to 
        <span style="color: #FF5666">true</span>.')
  ];
  $form['extra']['attributes']['keep'] = [
    '#type' => 'radios',
    '#title' => t('Keep'),
    '#description' => t('If <span style="color: #FF5666">true</span>, keep columns 
        matching the value, if <span style="color: #FF5666">false</span> discard 
        columns matching the value. Used when <span style="color: #FF5666">type</span> 
        is either <span style="color: #FF5666">static_value</span> or 
        <span style="color: #FF5666">param_value</span>.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
    '#default_value' => 'true',
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('Target value of the operations - has slightly different 
      meanings depending on type. For instance when <span style="color: #FF5666">type</span> is 
      <span style="color: #FF5666">add_value</span> it is the value to add to the list 
      and when <span style="color: #FF5666">type</span> is 
      <span style="color: #FF5666">static_value</span> it is the value compared against.')
  ];
  $form['extra']['attributes']['ref_attribute'] = [
    '#type' => 'textfield',
    '#title' => t('Reference attribute'),
    '#description' => t('Only used when <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">param_value</span>. Period (<span style="color: #FF5666">.</span>) 
        separated attribute chain of input (<span style="color: #FF5666">ref</span>) 
        attributes to use as value for filter.'),
  ];
  $form['extra']['attributes']['index'] = [
    '#type' => 'textfield',
    '#title' => t('Index'),
    '#description' => t('Used when <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">add_value</span>, it is the index into the 
        list to add the option to. If not set, the option will be added to 
        the end of the list.'),
  ];
  $form['extra']['attributes']['meta_ref'] = [
    '#type' => 'textfield',
    '#title' => t('Meta reference'),
    '#description' => t('Only used when <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">remove_value</span>. Dataset to look for the 
        value of metadata <span style="color: #FF5666">key</span> to remove from the list.')
  ];
  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}