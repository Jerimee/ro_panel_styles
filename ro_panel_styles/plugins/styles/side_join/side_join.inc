<?php

/**
 * @file
 * Changes link lists into nice buttons
 */

$plugin = array(
  'title' => t('Sidebar join Button'),
  'description' => t('The join button in the sidebar'),
  'render pane' => 'ro_panel_styles_side_join_pane',
  'render region' => 'ro_panel_styles_side_join_region',
  'weight' => -10,
);

/**
 * Theme function for the pane style.
 */            
function theme_ro_panel_styles_side_join_pane($vars) {
  $content = $vars['content'];
  $pane = $vars['pane'];
  $display = $vars['display'];
  $plugin = $vars['style'];

  if (!isset($content->css_class)) {
    $content->css_class = '';
  }

  $content->css_class .= 'side-join';

  // if the style is gone or has no theme of its own, just display the output.
  return theme('panels_pane', array('content' => $content, 'pane' => $pane, 'display' => $display));
}

/**
 * Theme function for the region style.
 */
function theme_ro_panel_styles_side_join_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $panes = $vars['panes'];
  $settings = $vars['settings'];

  $output = '';
  $output .= '<div class="region region-' . $vars['region_id'] . ' side-join">';
  $output .= implode('<div class="panel-separator"></div>', $panes);
  $output .= '</div>';
  return $output;
}
