// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#include "XML_Output_Adapter_svnt.h"
#include "Cookies.h"
#include "ciao/Servant_Activator.h"
#include "ciao/Port_Activator_T.h"
#include "ace/SString.h"

namespace CIAO_FACET_CIAO_RACE
{
  template <typename T>
  PlanEgress_Servant_T<T>::PlanEgress_Servant_T (
    ::CIAO::RACE::CCM_PlanEgress_ptr executor,
    ::Components::CCMContext_ptr c)
    : executor_ ( ::CIAO::RACE::CCM_PlanEgress::_duplicate (executor)),
      ctx_ ( ::Components::CCMContext::_duplicate (c))
  {
  }

  template <typename T>
  PlanEgress_Servant_T<T>::~PlanEgress_Servant_T (void)
  {
  }

  template <typename T>
  ::CORBA::Boolean
  PlanEgress_Servant_T<T>::output_plan (
    const ::CIAO::RACE::Plan_Actions & plans
    ACE_ENV_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    return this->executor_->output_plan (
      plans
      ACE_ENV_ARG_PARAMETER);
  }

  template <typename T>
  ::CORBA::Object_ptr
  PlanEgress_Servant_T<T>::_get_component (
    ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC (( ::CORBA::SystemException))
  {
    ::Components::SessionContext_var sc =
      ::Components::SessionContext::_narrow (
        this->ctx_.in ()
        ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (sc.in ()))
    {
      return sc->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ::Components::EntityContext_var ec =
    ::Components::EntityContext::_narrow (
      this->ctx_.in ()
      ACE_ENV_ARG_PARAMETER);
    ACE_CHECK_RETURN ( ::CORBA::Object::_nil ());

    if (! ::CORBA::is_nil (ec.in ()))
    {
      return ec->get_CCM_object (
        ACE_ENV_SINGLE_ARG_PARAMETER);
    }

    ACE_THROW_RETURN ( ::CORBA::INTERNAL (), 0);
  }
}

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_XML_Output_Adapter_Impl
    {
      XML_Output_Adapter_Context::XML_Output_Adapter_Context (
        ::Components::CCMHome_ptr h,
        ::CIAO::Session_Container *c,
        XML_Output_Adapter_Servant *sv)
        : ::CIAO::Context_Impl_Base (h, c), 
          ::CIAO::Context_Impl<
              ::CIAO::RACE::CCM_XML_Output_Adapter_Context,
              XML_Output_Adapter_Servant,
              ::CIAO::RACE::XML_Output_Adapter,
              ::CIAO::RACE::XML_Output_Adapter_var
            > (h, c, sv)
      {
      }

      XML_Output_Adapter_Context::~XML_Output_Adapter_Context (void)
      {
      }

      // Operations for XML_Output_Adapter receptacles and event sources,
      // defined in ::CIAO::RACE::CCM_XML_Output_Adapter_Context.

      // CIAO-specific.

      XML_Output_Adapter_Context *
      XML_Output_Adapter_Context::_narrow (
        ::Components::SessionContext_ptr p
        ACE_ENV_ARG_DECL_NOT_USED)
      {
        return dynamic_cast<XML_Output_Adapter_Context *> (p);
      }

      XML_Output_Adapter_Servant::XML_Output_Adapter_Servant (
        ::CIAO::RACE::CCM_XML_Output_Adapter_ptr exe,
        ::Components::CCMHome_ptr h,
        const char *ins_name,
        ::CIAO::Home_Servant_Impl_Base *hs,
        ::CIAO::Session_Container *c,
        CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Servant_Impl_Base (h, hs, c, rec_pol_map),
          ::CIAO::Servant_Impl<
              ::POA_CIAO::RACE::XML_Output_Adapter,
              ::CIAO::RACE::CCM_XML_Output_Adapter,
              XML_Output_Adapter_Context
            > (exe, h, hs, c, rec_pol_map),
          ins_name_ (ins_name)
      {
        ACE_NEW (this->context_,
                 XML_Output_Adapter_Context (h, c, this));

        // Set the instance id of the component on the context

        this->context_->_ciao_instance_id (this->ins_name_);

        ACE_TRY_NEW_ENV
        {
          ::Components::SessionComponent_var scom =
            ::Components::SessionComponent::_narrow (
              exe
              ACE_ENV_ARG_PARAMETER);
          ACE_TRY_CHECK;

          if (! ::CORBA::is_nil (scom.in ()))
          {
            scom->set_session_context (
              this->context_
              ACE_ENV_ARG_PARAMETER);
            ACE_TRY_CHECK;
          }

          this->populate_port_tables (
            ACE_ENV_SINGLE_ARG_PARAMETER);
          ACE_TRY_CHECK;
        }

        ACE_CATCHANY
        {
        }

        ACE_ENDTRY;
      }

      XML_Output_Adapter_Servant::~XML_Output_Adapter_Servant (void)
      {
      }

      void
      XML_Output_Adapter_Servant::set_attributes (
        const ::Components::ConfigValues &descr
        ACE_ENV_ARG_DECL)
      {
        ACE_ENV_EMIT_CODE (ACE_UNUSED_ARG (ACE_TRY_ENV));

        for ( ::CORBA::ULong i = 0; i < descr.length (); ++i)
        {
          const char *descr_name = descr[i]->name ();
          ::CORBA::Any &descr_value = descr[i]->value ();

          ACE_UNUSED_ARG (descr_name);
          ACE_UNUSED_ARG (descr_value);
        }
      }

      ::CIAO::RACE::PlanEgress_ptr
      XML_Output_Adapter_Servant::provide_plan_egress (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (! ::CORBA::is_nil (this->provide_plan_egress_.in ()))
        {
          return ::CIAO::RACE::PlanEgress::_duplicate (this->provide_plan_egress_.in ());
        }

        ::CORBA::Object_var obj =
          this->provide_plan_egress_i (ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::PlanEgress::_nil ());

        ::CIAO::RACE::PlanEgress_var fo =
          ::CIAO::RACE::PlanEgress::_narrow (obj.in ()
                                             ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::PlanEgress::_nil ());

        this->provide_plan_egress_ = fo;
        return ::CIAO::RACE::PlanEgress::_duplicate (this->provide_plan_egress_.in ());
      }

      ::CORBA::Object_ptr
      XML_Output_Adapter_Servant::provide_plan_egress_i (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::CORBA::Object_ptr ret =
          this->lookup_facet ("plan_egress");

        if (! ::CORBA::is_nil (ret))
        {
          return ret;
        }

        ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::PlanEgress_Servant,
            ::CIAO::RACE::CCM_PlanEgress,
            ::Components::CCMContext,
            XML_Output_Adapter_Servant
          > *tmp = 0;

        typedef ::CIAO::Port_Activator_T<
            ::CIAO_FACET_CIAO_RACE::PlanEgress_Servant,
            ::CIAO::RACE::CCM_PlanEgress,
            ::Components::CCMContext,
            XML_Output_Adapter_Servant
          >
        MACRO_MADNESS_TYPEDEF;

        ACE_CString obj_id (this->ins_name_);
        obj_id += "_plan_egress";

        ACE_NEW_THROW_EX (tmp,
                          MACRO_MADNESS_TYPEDEF (
                            obj_id.c_str (),
                            "plan_egress",
                            ::CIAO::Port_Activator::Facet,
                            0,
                            this->context_,
                            this),
                          ::CORBA::NO_MEMORY ());

        ::CIAO::Servant_Activator *sa = 
        this->container_->ports_servant_activator ();

        if (!sa->register_port_activator (tmp))
        {
          return ::CIAO::RACE::PlanEgress::_nil ();
        }

        ::CORBA::Object_var obj =
          this->container_->generate_reference (
            obj_id.c_str (),
            "IDL:CIAO/RACE/PlanEgress:1.0",
            ::CIAO::Container::Facet_Consumer
            ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::PlanEgress::_nil ());

        this->add_facet ("plan_egress",
                         obj.in ()
                         ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN ( ::CIAO::RACE::PlanEgress::_nil ());

        return obj._retn ();
      }

      ::Components::Cookie *
      XML_Output_Adapter_Servant::connect (
        const char *name,
        ::CORBA::Object_ptr connection
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::AlreadyConnected,
                       ::Components::ExceededConnectionLimit))
      {
        // If the component has no receptacles, this will be unused.
        ACE_UNUSED_ARG (connection);

        if (name == 0)
        {
          ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
      }

      ::CORBA::Object_ptr
      XML_Output_Adapter_Servant::disconnect (
        const char *name,
        ::Components::Cookie * ck
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::CookieRequired,
                       ::Components::NoConnection))
      {
        ACE_UNUSED_ARG (ck);

        if (name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::CORBA::Object::_nil ());
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (),
                          ::CORBA::Object::_nil ());
      }

      ::Components::ReceptacleDescriptions *
      XML_Output_Adapter_Servant::get_all_receptacles (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::ReceptacleDescriptions *retval = 0;
        ACE_NEW_RETURN (retval,
                        ::Components::ReceptacleDescriptions,
                        0);
        ::Components::ReceptacleDescriptions_var safe_retval = retval;
        safe_retval->length (0UL);

        return safe_retval._retn ();
      }

      void
      XML_Output_Adapter_Servant::connect_consumer (
        const char * emitter_name,
        ::Components::EventConsumerBase_ptr consumer
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::AlreadyConnected,
                       ::Components::InvalidConnection))
      {
        if (emitter_name == 0)
        {
          ACE_THROW ( ::CORBA::BAD_PARAM ());
        }

        ACE_UNUSED_ARG (consumer);
        ACE_THROW ( ::Components::InvalidName ());
      }

      ::Components::EventConsumerBase_ptr
      XML_Output_Adapter_Servant::disconnect_consumer (
        const char *source_name
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::NoConnection))
      {
        if (source_name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::Components::EventConsumerBase::_nil ());
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (),
                          ::Components::EventConsumerBase::_nil ());
      }

      ::Components::PublisherDescriptions *
      XML_Output_Adapter_Servant::get_all_publishers (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::PublisherDescriptions *retval = 0;
        ACE_NEW_RETURN (retval,
                        ::Components::PublisherDescriptions,
                        0);
        ::Components::PublisherDescriptions_var safe_retval = retval;
        safe_retval->length (0UL);

        return safe_retval._retn ();
      }

      ::Components::EmitterDescriptions *
      XML_Output_Adapter_Servant::get_all_emitters (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ::Components::EmitterDescriptions *retval = 0;
        ACE_NEW_RETURN (retval,
                        ::Components::EmitterDescriptions,
                        0);
        ::Components::EmitterDescriptions_var safe_retval = retval;
        safe_retval->length (0UL);

        return safe_retval._retn ();
      }

      ::Components::Cookie *
      XML_Output_Adapter_Servant::subscribe (
        const char *publisher_name,
        ::Components::EventConsumerBase_ptr subscribe
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection,
                       ::Components::ExceededConnectionLimit))
      {
        // Just in case there are no if blocks
        ACE_UNUSED_ARG (subscribe);

        if (publisher_name == 0)
        {
          ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (), 0);
      }

      ::Components::EventConsumerBase_ptr
      XML_Output_Adapter_Servant::unsubscribe (
        const char *publisher_name,
        ::Components::Cookie *ck
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException,
                       ::Components::InvalidName,
                       ::Components::InvalidConnection))
      {
        // Just in case there are no if blocks
        ACE_UNUSED_ARG (ck);

        if (publisher_name == 0)
        {
          ACE_THROW_RETURN ( ::Components::InvalidName (),
                            ::Components::EventConsumerBase::_nil ());
        }

        ACE_THROW_RETURN ( ::Components::InvalidName (),
                          ::Components::EventConsumerBase::_nil ());
      }

      ::CORBA::Object_ptr
      XML_Output_Adapter_Servant::get_facet_executor (
        const char *name
        ACE_ENV_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        if (name == 0)
        {
          ACE_THROW_RETURN ( ::CORBA::BAD_PARAM (),
                            ::CORBA::Object::_nil ());
        }

        if (ACE_OS::strcmp (name, "plan_egress") == 0)
        {
          return this->executor_->get_plan_egress (ACE_ENV_SINGLE_ARG_PARAMETER);
        }

        return ::CORBA::Object::_nil ();
      }

      // Supported operations.

      // Component attribute operations.

      // Private method to populate the port tables.
      void
      XML_Output_Adapter_Servant::populate_port_tables (
        ACE_ENV_SINGLE_ARG_DECL)
      ACE_THROW_SPEC (( ::CORBA::SystemException))
      {
        ACE_ENV_ARG_NOT_USED;
        ::CORBA::Object_var obj_var;
        ::Components::EventConsumerBase_var ecb_var;

        obj_var =
          this->provide_plan_egress_i (
            ACE_ENV_SINGLE_ARG_PARAMETER);
        ACE_CHECK;
      }

      XML_Output_Adapter_Home_Servant::XML_Output_Adapter_Home_Servant (
        ::CIAO::RACE::CCM_XML_Output_Adapter_Home_ptr exe,
        const char *ins_name,
        ::CIAO::Session_Container *c,
        CIAO::REC_POL_MAP &rec_pol_map)
        : ::CIAO::Home_Servant_Impl_Base (c),
          ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::XML_Output_Adapter_Home,
                ::CIAO::RACE::CCM_XML_Output_Adapter_Home,
                XML_Output_Adapter_Servant
              > (exe, c, ins_name, rec_pol_map)
      {
      }

      XML_Output_Adapter_Home_Servant::~XML_Output_Adapter_Home_Servant (void)
      {
      }

      // Home operations.

      // Home supported interface operations.

      // Home factory and finder operations.

      // Home attribute operations.

      extern "C" XML_OUTPUT_ADAPTER_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_XML_Output_Adapter_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        ::CIAO::Session_Container *c,
        const char *ins_name,
        CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL)
      {
        if (p == 0)
        {
          return 0;
        }

        ::CIAO::RACE::CCM_XML_Output_Adapter_Home_var x =
        ::CIAO::RACE::CCM_XML_Output_Adapter_Home::_narrow (
          p
          ACE_ENV_ARG_PARAMETER);
        ACE_CHECK_RETURN (0);

        if (::CORBA::is_nil (x.in ()))
        {
          return 0;
        }

        return new
        XML_Output_Adapter_Home_Servant (
          x.in (),
          ins_name,
          c, rec_pol_map);
      }
    }
  }
}

