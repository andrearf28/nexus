// ----------------------------------------------------------------------------
///  \file   NextNew.h
///  \brief  
///
///  \author   <miquel.nebot@ific.uv.es>, <jmunoz@ific.uv.es>, 
///            <justo.martin-albo@ific.uv.es>
///  \date     Sept 2013
///  \version  $Id$
///
///  Copyright (c) 2013-2015 NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef NEXTNEW_H
#define NEXTNEW_H

#include "BaseGeometry.h"

namespace nexus { class Next100Shielding; }
namespace nexus { class NextNewPedestal; }
namespace nexus { class NextNewCuCastle; }
namespace nexus { class NextNewVessel; }
namespace nexus { class NextNewIcs; }
namespace nexus { class NextNewInnerElements; }
namespace nexus {class BoxPointSampler;}
namespace nexus {class CylinderPointSampler;}
namespace nexus {class MuonsPointSampler;}
namespace nexus {class CalibrationSource;}

class G4LogicalVolume;
class G4GenericMessenger;


namespace nexus {

  class NextNew: public BaseGeometry {
  public:
    /// Constructor
    NextNew();

    /// Destructor
    ~NextNew();

    /// Generate a vertex within a given region of the geometry
    G4ThreeVector GenerateVertex(const G4String& region) const;

  private:
    void BuildExtScintillator(G4ThreeVector pos);
    void Construct();

  private:
    
    // Detector dimensions
    const G4double _lab_size; ///< Size of the air box containing the detector  
   
    //   G4double _pressure; ///< Pressure xenon gas

    // Pointers to logical volumes
    G4LogicalVolume* _lab_logic;
    G4LogicalVolume* _shielding_air_logic;

    //Detector parts
    Next100Shielding* _shielding;
    NextNewPedestal* _pedestal;
    // NextNewCuCastle* _cu_castle;
    NextNewVessel* _vessel;   
    NextNewIcs* _ics;
    NextNewInnerElements* _inner_elements;
    
    BoxPointSampler* _lab_gen; ///< Vertex generator
    CylinderPointSampler* _lat_source_gen;
    /* CylinderPointSampler* _source_gen_up; */
    MuonsPointSampler* _muon_gen; ///< Vertex generator for muons

    /// Messenger for the definition of control commands
    //  G4GenericMessenger* _msg;

    // Rotation around Y and displacement of the whole geometry in the g4 system of reference
    G4ThreeVector _displ;
    G4double _rot_angle;

    // Messenger for the definition of control commands
    G4GenericMessenger* _msg; 

    // Kind of block of lead on the lateral port placed to shield source
    G4String _lead_block;
    G4double _lead_thick;
    
    // Incapsulated calibration source volume
    CalibrationSource* _cal;
    // Distance from the end of the lateral feedthrough to the source pos
    //   G4double _ext_source_distance;
  };
  
} // end namespace nexus

#endif
