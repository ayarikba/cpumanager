{
  description = "Dev environment for C++ Qt project";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-24.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.simpleFlake {
      inherit self nixpkgs;
      packages = pkgs: {
        default = pkgs.mkShell {
          buildInputs = [
            pkgs.gcc
            pkgs.cmake
            pkgs.ninja
            pkgs.pkg-config

            # Qt
            pkgs.qt6.full

            # OCCT (optional)
            pkgs.opencascade-occt

            # Tools you may want
            pkgs.ccache
            pkgs.git
          ];

          shellHook = ''
            export CC=gcc
            export CXX=g++
            export QT_PLUGIN_PATH=${pkgs.qt6.qtbase}/${pkgs.qt6.qtbase.qtPluginPrefix}
            echo "🎉 Nix dev shell active: $(pwd)"
          '';
        };
      };
    };
}
