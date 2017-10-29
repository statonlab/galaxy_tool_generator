<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs', $component, 'tool > outputs');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    // TODO
    $form = array_merge($form, get_edit_component_base_form_elements($form, 'outputs'));

    // TODO
    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['provided_metadata_style'] = [
        '#type' => 'select',
        '#title' => t('Provided metadata style'),
        '#description' => t('Style used for tool provided metadata file (i.e. galaxy.json) - 
      this can be either “legacy” or “default”. The default of tools with a profile of 17.09 or 
      newer are “default”, and “legacy” for older and tools and tools without a specified profile. 
      A discussion of the differences between the styles can be found at https://github.com/galaxyproject/galaxy/pull/4437.'),
        // TODO: need a full list of options.
        '#options' => drupal_map_assoc([
            '',
            'legacy',
            'default',
        ]),
        '#default_vlaue' => '',
    ];
    $form['extra']['attributes']['provided_metadata_file'] = [
        '#type' => 'textfield',
        '#title' => t('Provided metadata file'),
        '#description' => t('Path relative to tool’s working directory to load tool 
      provided metadata from. This metadata can describe dynamic datasets to load, 
      dynamic collection contents, as well as simple metadata (e.g. name, dbkey, etc...) 
      and datatype specific metadata for declared outputs. More information can be 
      found ' . l('here', 'http://planemo.readthedocs.io/en/latest/writing_advanced.html#tool-provided-metadata') .
            '. The default is galaxy.json.'),
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}