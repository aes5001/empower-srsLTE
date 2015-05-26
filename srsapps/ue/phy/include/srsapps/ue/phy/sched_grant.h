/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2013-2015 The srsLTE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsLTE library.
 *
 * srsLTE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsLTE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */



#include "srslte/srslte.h"
#include "srsapps/common/queue.h"

#ifndef UESCHEDGRANT_H
#define UESCHEDGRANT_H

namespace srslte {
namespace ue {  

  /* Uplink/Downlink scheduling grant generated by a successfully decoded PDCCH */ 
  class sched_grant {
  public:
    typedef enum {
      RNTI_TYPE_NOTDEFINED = 0,
      RNTI_TYPE_CRNTI,
      RNTI_TYPE_RA,
      RNTI_TYPE_SPS,
      RNTI_TYPE_TEMP,
      RNTI_TYPE_SIRNTI,
      RNTI_TYPE_PRNTI,
      RNTI_TYPE_TPC_PUSCH,
      RNTI_TYPE_TPC_PUCCH
    } rnti_type_t; 

    sched_grant(uint16_t rnti_) {
      rnti = rnti_; 
      rnti_type = RNTI_TYPE_NOTDEFINED; 
    }
    sched_grant(rnti_type_t rnti_type_, uint16_t rnti_) {
      rnti = rnti_; 
      rnti_type = rnti_type_; 
    }
    uint16_t get_rnti() {
      return rnti; 
    }
    bool is_temp_rnti() {
      return rnti_type == RNTI_TYPE_TEMP; 
    }
    bool is_crnti() {
      return rnti_type == RNTI_TYPE_CRNTI;
    }
    bool is_ra_rnti() {
      return rnti_type == RNTI_TYPE_RA; 
    }
    bool is_SPS_rnti() {
      return rnti_type == RNTI_TYPE_SPS; 
    }
    bool is_sys_rnti() {
      return (rnti_type == RNTI_TYPE_SIRNTI || rnti_type == RNTI_TYPE_PRNTI);
    }
    bool is_tpc_rnti() {
      return (rnti_type == RNTI_TYPE_TPC_PUSCH || rnti_type == RNTI_TYPE_TPC_PUCCH);
    }
    virtual uint32_t get_rv()            = 0; 
    virtual void     set_rv(uint32_t rv) = 0; 
    virtual bool     get_ndi()           = 0; 
    virtual void     set_ndi(bool value) = 0; 
    virtual bool     is_sps_release()    = 0; 
    virtual uint32_t get_tbs()           = 0; 
  protected: 
    uint16_t            rnti; 
    rnti_type_t         rnti_type; 
  };
 
}
}

#endif