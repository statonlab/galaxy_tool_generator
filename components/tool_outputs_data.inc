<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > outputs > data');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data(&$form) {
  unset($form['validation']);
  unset($form['display']);

  // TODO
  $form = array_merge($form, get_edit_component_base_form_elements($form, 'data'));

  // TODO
  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this output. This <span style="color: #FF5666">name</span> is 
        used as the Cheetah variable containing the Galaxy assigned output path in command and 
        configfile elements. The <span style="color: #FF5666">name</span> should not contain 
        <span style="color: #FF5666">pipes</span> or <span style="color: #FF5666">periods(.)</span>.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['auto_format'] = [
    '#type' => 'radios',
    '#title' => t('Auto format'),
    '#description' => t('If <span style="color: #FF5666">true</span>, this output 
        will sniffed and its format determined automatically by Galaxy.'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
  ];
  $form['extra']['attributes']['format'] = [
    '#type' => 'textfield',
    '#title' => t('Format'),
    '#description' => t('The short name for the output datatype. The valid values 
      for format can be found in ' . l('/config/datatypes_conf.xml.sample', 'https://github.com/galaxyproject/galaxy/blob/dev/config/datatypes_conf.xml.sample') .
      '(e.g. <span style="color: #FF5666">format="pdf"</span> or <span style="color: #FF5666">format="fastqsanger"</span>).	'),
  ];
  $form['extra']['attributes']['format_source'] = [
    '#type' => 'textfield',
    '#title' => t('Format source'),
    '#description' => t('This sets the data type of the output file to be the 
      same format as that of a tool input dataset.')
  ];
  $form['extra']['attributes']['default_identifier_source'] = [
    '#type' => 'textfield',
    '#title' => t('Default identifier source'),
    '#description' => t('Sets the source of element identifier to the specified input. 
      This only applies to collections that are mapped over a non-collection input 
      and that have equivalent structures.')
  ];
  $form['extra']['attributes']['metadata_source'] = [
    '#type' => 'textfield',
    '#title' => t('Metadata source'),
    '#description' => t('This copies the metadata information from the tool’s 
      input dataset. This is particularly useful for interval data types where 
      the order of the columns is not set.')
  ];
  $form['extra']['attributes']['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('This will be the name of the history item for the output 
        data set. The string can include structure like 
        <span style="color: #FF5666">&#36{&lt;some param name&gt;.&lt;some attribute&gt;}</span>, 
        as discussed for command line parameters in the <span style="color: #FF5666">&lt;command&gt;</span> 
        tag set section above. The default label is <span style="color: #FF5666">&#36{tool.name}</span> on 
        <span style="color: #FF5666">&#36{on_string}</span>.'),
  ];
  $form['extra']['attributes']['from_work_dir'] = [
    '#type' => 'textfield',
    '#title' => t('From work directory'),
    '#description' => t('Relative path to a file produced by the tool in its 
      working directory. Output’s contents are set to this file’s contents.'),
  ];
  $form['extra']['attributes']['hidden'] = [
    '#type' => 'radios',
    '#title' => t('Hidden'),
    '#description' => t('Boolean indicating whether to hide dataset in the 
      history view. (Default is <span style="color: #FF5666">false</span>.)'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
    '#default_value' => 'false',
  ];
}