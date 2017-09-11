<?php

/**
 * function to generate an associate array of tag-value pairs.
 *
 * @return array
 */
function get_param_basetype_form_elements() {
  return [
    'name' => [
      '#type' => 'textfield',
      '#title' => 'name',
      '#description' => t('Name for this element. This name is used as the 
        Cheetah variable containing the user-supplied parameter name in command 
        and configfile elements. The name should not contain pipes or periods 
        (e.g. .). Some “reserved” names are REDIRECT_URL, DATA_URL, GALAXY_URL.'),
      '#required' => TRUE,
    ],
    'argument' => [
      '#type' => 'textfield',
      '#title' => 'argument',
      '#description' => t('If the parameter reflects just one command line 
        argument of a certain tool, this tag should be set to that particular 
        argument. It is rendered in parenthesis after the help section, and 
        it will create the name attribute from the argument attribute by 
        stripping the dashes (e.g. if argument="--sensitive" then 
        name="sensitive" is implicit).	')
    ],
    'label' => [
      '#type' => 'textfield',
      '#title' => 'label',
      '#description' => t('The attribute value will be displayed on the tool 
        page as the label of the form field (label="Sort Query").	')
    ],
    'help' => [
      '#type' => 'textarea',
      '#title' => 'help',
      '#description' => t('Short bit of text, rendered on the tool form just 
        below the associated field to provide information about the field. 
        Find the Intergalactic Utilities Commision suggested best practices 
        for this element here.	')
    ],
    'optional' => [
      '#type' => 'radios',
      '#title' => 'optional',
      '#description' => t('If false, parameter must have a value. Defaults to “false”.	'),
      '#options' => drupal_map_assoc([
        'False',
        'True',
      ]),
    ],
    'refresh_on_change' => [
      '#type' => 'radios',
      '#title' => 'refresh_on_change',
      '#description' => t('Force a reload of the tool panel when the value of 
        this parameter changes to allow code file processing. See deprecation-like 
        notice for code blocks.	'),
      '#options' => drupal_map_assoc([
        'False',
        'True',
      ]),
    ],
  ];
}