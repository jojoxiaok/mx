// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Strings.h"
#include "mx/core/elements/HammerOnAttributes.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( HammerOnAttributes )
        MX_FORWARD_DECLARE_ELEMENT( HammerOn )

        inline HammerOnPtr makeHammerOn() { return std::make_shared<HammerOn>(); }
		inline HammerOnPtr makeHammerOn( const XsString& value ) { return std::make_shared<HammerOn>( value ); }
		inline HammerOnPtr makeHammerOn( XsString&& value ) { return std::make_shared<HammerOn>( std::move( value ) ); }

        class HammerOn : public ElementInterface
        {
        public:
            HammerOn();
            HammerOn( const XsString& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            HammerOnAttributesPtr getAttributes() const;
            void setAttributes( const HammerOnAttributesPtr& attributes );
            XsString getValue() const;
            void setValue( const XsString& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            XsString myValue;
            HammerOnAttributesPtr myAttributes;
        };
    }
}
