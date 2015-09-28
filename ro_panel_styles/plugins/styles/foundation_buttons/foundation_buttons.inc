<?php

/**
 * @file
 * Adds the foundation button class to a pane
 */

$plugin = array(
  'title' => t('Foundation Button'),
  'description' => t('Style this like a Foundation 5 button'),
  'render pane' => 'ro_panel_styles_foundation_buttons_pane',
  'render region' => 'ro_panel_styles_foundation_buttons_region',
  'weight' => -10,
);

/**
 * Theme function for the pane style.
 */
function theme_ro_panel_styles_foundation_buttons_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];
  $plugin = $vars['style'];
 
  if (!isset($content->css_class)) {
    $content->css_class = '';
  }
  
  $content->css_class .= ' button';

  // if the style is gone or has no theme of its own, just display the output.
  return theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));
}

/**
 * Theme function for the region style.
 */
function theme_ro_panel_styles_foundation_buttons_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  $output = '';
  $output .= '<div class="region region-' . $vars['region_id'] . ' button">';
  $output .= implode('<div class="panel-separator"></div>', $panes);
  $output .= '</div>';
  return $output;
}
