# RelayBox
An Arduino that relays the flash signal of two [UI-3060CP Rev. 2](https://en.ids-imaging.com/store/products/cameras/ui-3060cp-rev-2.html) cameras to switch four lasers in the [MatchBox](https://integratedoptics.com/products/wavelength-combiners) combiner according to a specific preset.  

## Circuit diagram 

![RelayBox](https://user-images.githubusercontent.com/89871015/175886793-4d19a346-352b-48da-ae14-5c24009df166.png)

## Commands for presets

For each laser we have four commands
- 'LxxxOFF' always off.
- 'LxxxON' always on.
- 'LxxxF1' laser is switched on during the flash signal of the 1st camera.
- 'LxxxF2' laser is switched on during the flash signal of the 2nd camera.

Where 'xxx' is substituted by 405, 488, 520 or 638.

Alternating laser excitation between F1 for one frame and F2 for the next (ALEX) is set by selecting the preferred lasers and sending 'ALEXON' command. To deactivate ALEX send 'ALEXOFF'.

Commands are preferably sent in one line e.g., 'ALEXONL405OFFL488OFFL520F1L638F2'.

## Time response

![Graph4](https://user-images.githubusercontent.com/89871015/135933223-2a2900b8-f8c8-4a3a-90d9-00d694d6346f.png)

## Control Software

[microEye](https://github.com/samhitech/microEye) control module connects to the laser RelayBox and controls it alongside with the [MatchBox](https://integratedoptics.com/products/wavelength-combiners) combiner, for further details check the provided links.

![control_module](https://user-images.githubusercontent.com/89871015/141841883-d37c4979-c8aa-4e1f-b1b9-84bdd819c828.png)

## Authors

Mohammad Nour Alsamsam

[![Twitter URL](https://img.shields.io/twitter/url/https/twitter.com/samhightech.svg?style=social&label=Follow%20%40samhightech)](https://twitter.com/samhightech)
    
